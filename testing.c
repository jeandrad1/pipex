#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

typedef struct {
    char **cmd1;
    char **cmd2;
    char *infile;
    char *outfile;
} t_args;

void ft_free_pipex(t_args *pipex) {
    if (pipex->cmd1) {
        for (int i = 0; pipex->cmd1[i] != NULL; i++) {
            free(pipex->cmd1[i]);
        }
        free(pipex->cmd1);
    }

    if (pipex->cmd2) {
        for (int i = 0; pipex->cmd2[i] != NULL; i++) {
            free(pipex->cmd2[i]);
        }
        free(pipex->cmd2);
    }
}

void ft_exit(t_args *pipex, const char *error_message, int exit_code) {
    ft_free_pipex(pipex);
    if (error_message) {
        fprintf(stderr, "%s\n", error_message);
    }
    exit(exit_code);
}

void ft_init_pipex(t_args *pipex) {
    // Initialize pipex structure
    pipex->cmd1 = NULL;
    pipex->cmd2 = NULL;
    pipex->infile = NULL;
    pipex->outfile = NULL;
}

char **split_command(const char *command) {
    char **args = NULL;
    char *cmd_copy = strdup(command);
    char *token = strtok(cmd_copy, " ");
    int count = 0;

    while (token) {
        args = realloc(args, sizeof(char *) * (count + 1));
        args[count] = strdup(token);
        count++;
        token = strtok(NULL, " ");
    }
    args = realloc(args, sizeof(char *) * (count + 1));
    args[count] = NULL;

    free(cmd_copy);
    return args;
}

void check_and_set_env() {
    if (getenv("PATH") == NULL) {
        setenv("PATH", "/usr/bin:/bin", 1);
    }
    // Add checks for other essential environment variables if needed
}

void ft_parse(int argc, char **argv, t_args *pipex) {
    if (argc != 5) {
        ft_exit(pipex, "Usage: ./pipex infile command1 command2 outfile", EXIT_FAILURE);
    }
    pipex->infile = argv[1];
    pipex->cmd1 = split_command(argv[2]);
    pipex->cmd2 = split_command(argv[3]);
    pipex->outfile = argv[4];

    // Check if infile is valid
    int infile_fd = open(pipex->infile, O_RDONLY);
    if (infile_fd == -1) {
        ft_exit(pipex, "Error: Unable to open infile", EXIT_FAILURE);
    }
    close(infile_fd);

    // Check and set essential environment variables
    check_and_set_env();
}

void ft_exec_cmd(t_args *pipex) {
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        ft_exit(pipex, "Error: Unable to create pipe", EXIT_FAILURE);
    }

    pid_t pid1 = fork();
    if (pid1 == -1) {
        ft_exit(pipex, "Error: Unable to fork process for cmd1", EXIT_FAILURE);
    } else if (pid1 == 0) {
        // Child process for command1
        int infile_fd = open(pipex->infile, O_RDONLY);
        if (infile_fd == -1) {
            ft_exit(pipex, "Error: Unable to open infile in child process", EXIT_FAILURE);
        }
        dup2(infile_fd, STDIN_FILENO);
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(infile_fd); // Close infile_fd after duplicating
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        execvp(pipex->cmd1[0], pipex->cmd1);
        ft_exit(pipex, "Error: execvp failed for cmd1", EXIT_FAILURE);
    }

    pid_t pid2 = fork();
    if (pid2 == -1) {
        ft_exit(pipex, "Error: Unable to fork process for cmd2", EXIT_FAILURE);
    } else if (pid2 == 0) {
        // Child process for command2
        int outfile_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (outfile_fd == -1) {
            ft_exit(pipex, "Error: Unable to open outfile in child process", EXIT_FAILURE);
        }
        dup2(pipe_fd[0], STDIN_FILENO);
        dup2(outfile_fd, STDOUT_FILENO);
        close(outfile_fd); // Close outfile_fd after duplicating
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        execvp(pipex->cmd2[0], pipex->cmd2);
        ft_exit(pipex, "Error: execvp failed for cmd2", EXIT_FAILURE);
    }

    // Parent process
    close(pipe_fd[0]);
    close(pipe_fd[1]);

    int status1, status2;
    if (waitpid(pid1, &status1, 0) == -1) {
        ft_exit(pipex, "Error: waitpid failed for cmd1", EXIT_FAILURE);
    }
    if (waitpid(pid2, &status2, 0) == -1) {
        ft_exit(pipex, "Error: waitpid failed for cmd2", EXIT_FAILURE);
    }

    if (status1 != 0) {
        ft_exit(pipex, "Error: cmd1 failed", status1);
    }

    if (status2 != 0) {
        ft_exit(pipex, "Error: cmd2 failed", status2);
    }
}

// Main function
int main(int argc, char **argv) {
    t_args pipex;

    memset(&pipex, 0, sizeof(t_args));
    printf("memset OK\n");
    ft_init_pipex(&pipex);
    printf("init OK\n");
    ft_parse(argc, argv, &pipex);
    printf("parse OK\n");
    ft_exec_cmd(&pipex);
    printf("exec OK\n");
    ft_free_pipex(&pipex);
    printf("free OK\n");
    // Return the program
    return (EXIT_SUCCESS);
}