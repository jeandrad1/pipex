# Pipex

Implementation of Unix pipe behavior, allowing sequential command execution.

## Description

The program simulates the behavior of the Unix pipe (`|`). It takes two commands as arguments and executes the first one, passing its standard output as standard input to the second, allowing input from a file and output to a file.

## Functionality

Shell equivalence:
```bash
./pipex infile cmd1 cmd2 outfile
# Is equivalent to:
< infile cmd1 | cmd2 > outfile
```

## Included Files

General structure:
- `pipex.c` - Main function and control logic
- `pipex.h` - Header file
- Utility files
- Directory `libft/` - Custom library

## Compilation

```bash
make              # Compile pipex
make clean        # Clean object files
make fclean       # Clean everything
make re           # Recompile from scratch
```

## Usage

```bash
./pipex infile "command1" "command2" outfile
```

### Example

```bash
./pipex input.txt "cat" "grep word" output.txt
# Reads input.txt, passes it to cat, then to grep, and writes to output.txt
```

## Arguments

| Argument | Description |
|---|---|
| `infile` | Input file (must exist) |
| `cmd1` | First command to execute |
| `cmd2` | Second command to execute |
| `outfile` | Output file (created or overwritten) |

## Requirements

- C compiler (gcc, clang, etc.)
- Make
- Linux or macOS
- Access to system commands (cat, grep, etc.)

## Features

- Uses pipes for inter-process communication
- Child process forking
- Standard input/output redirection
- File and command error handling
- Executable search in PATH

## Process Management

The program:
1. Opens the input file
2. Creates a pipe
3. Forks a child process to execute cmd1
4. Forks another child process to execute cmd2
5. Waits for both processes to finish
6. Closes files and pipes

## Error Handling

- Validates input file existence
- Checks read/write permissions
- Handles commands not found
- Reports system errors appropriately

---

Last updated: December 2025
