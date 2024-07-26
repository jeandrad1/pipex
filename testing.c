#include "includes/pipex.h"

void	ft_free_pipex(t_args *pipex)
{
	int	i;

	i = 0;
	if (pipex->cmd1)
	{
		while (pipex->cmd1[i] != NULL)
		{
			free(pipex->cmd1[i]);
			i++;
		}
		free(pipex->cmd1);
	}
	i = 0;
	if (pipex->cmd2)
	{
		while (pipex->cmd2[i] != NULL)
		{
			free(pipex->cmd2[i]);
			i++;
		}
		free(pipex->cmd2);
	}
}

void	ft_exit(t_args *pipex, const char *error_message, int exit_code)
{
	ft_free_pipex(pipex);
	if (error_message)
		perror(error_message);
	exit(exit_code);
}



// Initialize the pipex structure
void	ft_init_pipex(t_args *pipex)
{
	pipex->infile = NULL;
	pipex->outfile = NULL;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
}

// Check if the string is empty or contains only spaces
static int	check_void(const char *str)
{
	if (str == NULL)
		return (1);
	while (*str)
	{
		if (!ft_isspace((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

// Check if PATH is set and set it if not it displays an error message and exits
static void	check_and_set_env(char **env)
{
	int	path_found;

	path_found = 0;
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
		{
			path_found = 1;
			break ;
		}
		env++;
	}
	if (!path_found)
	{
		perror("Error: PATH not set");
		exit(EXIT_FAILURE);
	}
}

// Split the command into an array of strings
// It uses tokenize_command to split the command by spaces
// And reallocates the array of strings to store each token
// It returns the array of strings
static char	**split_command(const char *command)
{
	int		count;
	char	**args;

	args = tokenize_command(command, &count);
	args = allocate_args(args, count);
	args[count] = NULL;
	return (args);
}

// Parse the arguments
// Uses the split_command function to split the commands
// And checks if the infile and outfile can be opened
// Check the environment variables
void	ft_parse(int argc, char **argv, t_args *pipex)
{
	int	infile_fd;
	int	i;

	i = 0;
	if (argc != 5)
		ft_exit(pipex, "Error: invalid number of arguments", EXIT_FAILURE);
	if (check_void(argv[2]) || check_void(argv[3]))
		ft_exit(pipex, "Error: command arguments cannot be empty or whitespace",
			EXIT_FAILURE);
	pipex->infile = argv[1];
	pipex->cmd1 = split_command(argv[2]);
	pipex->cmd2 = split_command(argv[3]);
	pipex->outfile = argv[4];
	infile_fd = open(pipex->infile, O_RDONLY);
	if (infile_fd == -1)
		ft_exit(pipex, "Error: Unable to open infile", EXIT_FAILURE);
	close(infile_fd);
	check_and_set_env(pipex->env);
}

// Function to allocate memory and copy token
static void	allocate_and_copy_token(char ***args, int count, const char *token)
{
	int	i;

	*args = allocate_args(*args, count);
	(*args)[count] = ft_strdup(token);
	if (!(*args)[count])
	{
		i = 0;
		while (i < count)
		{
			free((*args)[i]);
			i++;
		}
		free(*args);
		perror("Error: memory allocation failed");
		exit(EXIT_FAILURE);
	}
}

// Function to handle memory allocation and error checking
char	**allocate_args(char **args, int count)
{
	int		i;
	char	**new_args;

	new_args = malloc(sizeof(char *) * (count + 1));
	if (new_args == NULL)
	{
		i = 0;
		while (i < count)
		{
			free(args[i]);
			i++;
		}
		free(args);
		perror("Error: memory allocation failed");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < count)
	{
		new_args[i] = args[i];
		i++;
	}
	return (new_args);
}

// Function to tokenize the command string
char	**tokenize_command(const char *command, int *count)
{
	char	**args;
	char	*cmd_copy;
	char	*token;

	args = NULL;
	cmd_copy = ft_strdup(command);
	if (cmd_copy == NULL)
	{
		perror("Error: empty command");
		exit(EXIT_FAILURE);
	}
	token = ft_strtok(cmd_copy, " ");
	*count = 0;
	while (token)
	{
		allocate_and_copy_token(&args, *count, token);
		(*count)++;
		token = ft_strtok(NULL, " ");
	}
	free(cmd_copy);
	return (args);
}

static void	handle_child1(t_args *pipex, int pipe_fd[2])
{
	int	infile_fd;

	infile_fd = open(pipex->infile, O_RDONLY);
	if (infile_fd == -1)
		ft_exit(pipex, "Error: Unable to open infile in child process",
			EXIT_FAILURE);
	dup2(infile_fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(infile_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execvp(pipex->cmd1[0], pipex->cmd1);
	ft_exit(pipex, "Error: execvp failed for cmd1", EXEC_ERROR);
}

// Function to handle the child process for the second command
// Uses dup2 to redirect the input and output of the command
// Closes the file descriptors and executes the command 
static void	handle_child2(t_args *pipex, int pipe_fd[2])
{
	int	outfile_fd;

	outfile_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
		ft_exit(pipex, "Error: Unable to open outfile in child process",
			EXIT_FAILURE);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execvp(pipex->cmd2[0], pipex->cmd2);
	ft_exit(pipex, "Error: execvp failed for cmd2", EXEC_ERROR);
}

// Function to handle the parent process
// Closes the file descriptors and waits for the child processes to finish
// If the child processes fail it displays an error message and exits
static void	handle_parent(t_args *pipex, int pipe_fd[2], pid_t pid1, pid_t pid2)
{
	int	status1;
	int	status2;

	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (waitpid(pid1, &status1, 0) == -1)
		ft_exit(pipex, "Error: waitpid failed for cmd1", EXEC_ERROR);
	if (waitpid(pid2, &status2, 0) == -1)
		ft_exit(pipex, "Error: waitpid failed for cmd2", EXEC_ERROR);
	if (WIFEXITED(status1) == 0)
		ft_exit(pipex, "Command 1 not found", ARG_ERROR);
	if (WIFEXITED(status2) == 0)
		ft_exit(pipex, "Command 2 not found", ARG_ERROR);
}

// Function to execute the commands
// Creates a pipe and forks two child processes
// The child proocesses are concurrent and execute the commands
// The parent process waits for the child processes to finish
void	ft_exec_cmd(t_args *pipex)
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipe_fd) == -1)
		ft_exit(pipex, "Error: Unable to create pipe", EXEC_ERROR);
	pid1 = fork();
	if (pid1 == -1)
		ft_exit(pipex, "Error: Unable to fork process for cmd1", EXEC_ERROR);
	else if (pid1 == 0)
		handle_child1(pipex, pipe_fd);
	pid2 = fork();
	if (pid2 == -1)
		ft_exit(pipex, "Error: Unable to fork process for cmd2", EXEC_ERROR);
	else if (pid2 == 0)
		handle_child2(pipex, pipe_fd);
	handle_parent(pipex, pipe_fd, pid1, pid2);
}

int	main(int argc, char **argv, char **env)
{
	t_args	pipex;

	pipex.env = env;
	ft_init_pipex(&pipex);
	ft_parse(argc, argv, &pipex);
	ft_exec_cmd(&pipex);
	ft_free_pipex(&pipex);
	return (EXIT_SUCCESS);
}
