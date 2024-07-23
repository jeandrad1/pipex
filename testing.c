#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include "libft/libft.h"

typedef struct {
    char **cmd1;
    char **cmd2;
    char *infile;
    char *outfile;
} t_args;

void ft_init_pipex(t_args *pipex) {
    // Initialize pipex structure
    memset(pipex, 0, sizeof(t_args));   
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

void ft_parse(int argc, char **argv, t_args *pipex) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s infile command1 command2 outfile\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    pipex->infile = argv[1];
    pipex->cmd1 = split_command(argv[2]);
    pipex->cmd2 = split_command(argv[3]);
    pipex->outfile = argv[4];

    // Check if infile is valid
    int infile_fd = open(pipex->infile, O_RDONLY);
    if (infile_fd == -1) {
        perror("open infile");
        exit(EXIT_FAILURE);
    }
    close(infile_fd);
}

void ft_exec_cmd(t_args *pipex) {
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        // Child process for command1
        int infile_fd = open(pipex->infile, O_RDONLY);
        if (infile_fd == -1) {
            perror("open infile");
            exit(EXIT_FAILURE);
        }
        dup2(infile_fd, STDIN_FILENO);
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(infile_fd); // Close infile_fd after duplicating
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        execvp(pipex->cmd1[0], pipex->cmd1);
        perror("execvp cmd1");
        exit(EXIT_FAILURE);
    }

    pid_t pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
        // Child process for command2
        int outfile_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (outfile_fd == -1) {
            perror("open outfile");
            exit(EXIT_FAILURE);
        }
        dup2(pipe_fd[0], STDIN_FILENO);
        dup2(outfile_fd, STDOUT_FILENO);
        close(outfile_fd); // Close outfile_fd after duplicating
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        execvp(pipex->cmd2[0], pipex->cmd2);
        perror("execvp cmd2");
        exit(EXIT_FAILURE);
    }

    // Parent process
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

void ft_free_pipex(t_args *pipex) {
    for (int i = 0; pipex->cmd1[i] != NULL; i++) {
        free(pipex->cmd1[i]);
    }
    free(pipex->cmd1);

    for (int i = 0; pipex->cmd2[i] != NULL; i++) {
        free(pipex->cmd2[i]);
    }
    free(pipex->cmd2);
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