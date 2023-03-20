#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*str;
	t_envp	tenvp;

	// ft_basic_signal();
	if (ac != 1)
		return (0);
	if (!ft_strcmp(av[0], "minishell"))
		return (0);
	envp_init(&tenvp, envp);
	while (1)
	{
		str = readline("minishell$ ");
		tenvp.exit_status = 0;
		if (!str)
		{
			printf("exit\n");
			break ;
		}
		if (ft_strchr(str, '|'))
			pipex(str, tenvp);
		else
			run_cmd(str, tenvp);
		add_history(str);
		free(str);
	}
	return (0);
}
