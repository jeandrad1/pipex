#include "pipex.h"
// Function to display the error message
// It receives an integer value with the error code
static void	error_parsing(int error)
{
	if (error == 1)
		ft_printf("ERROR: Arguments error\n");
}

// Function to display the error message and exit the program
// After displaying the help information
int	exit_error(int error, int is_exit)
{
	error_parsing(error);
	if (is_exit)
		exit(error != NOTHING);
	return (error != NOTHING);
}