/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:02:17 by myko              #+#    #+#             */
/*   Updated: 2023/04/17 21:02:21 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_env_node *head, char **keys)
{
	int	i;

	g_exit_status = 0;
	i = 1;
	if (keys[1] == NULL)
		return ;
	while (keys[i] != NULL)
	{
		if (is_valid_name(UNSET_FUNC, keys[i], NULL))
			delete_node(head, keys[i]);
		else
			g_exit_status = 1;
		++i;
	}
}
