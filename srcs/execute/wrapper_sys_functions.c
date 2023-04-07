#include "minishell.h"

int	pipe_s(int fd[2])
{
	int	error_check;

	error_check = pipe(fd);
	if (error_check == -1)
	{
		g_exit_status = 1;
		perror("pipe");
		return (FALSE);
	}
	return (TRUE);
}

int	fork_s(void)
{
	int	error_check;

	error_check = fork();
	if (error_check == -1)
	{
		g_exit_status = 1;
		perror("fork");
		return (error_check);
	}
	return (error_check);
}

void	*malloc_s(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		ft_allocation_error();
	}
	return (ptr);
}