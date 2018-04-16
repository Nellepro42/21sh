/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 03:03:52 by neprocur          #+#    #+#             */
/*   Updated: 2017/07/17 02:04:34 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void		ft_get(t_shell *sh2)
{
	char	*pwd;

	pwd = getwd(NULL);
	ft_putendl(pwd);
	ft_strdel(&pwd);
}

void		write_env(t_shell *sh2)
{
	int		i;

	i = 0;
	if (sh2->env_cpy[i])
	{
		while (sh2->env_cpy[i])
		{
			ft_putendl(sh2->env_cpy[i]);
			i++;
		}
	}
}

int		ft_builtins(t_shell *sh2, char **arg)
{
	if (sh2->arg[0])
	{
		if (ft_strcmp(sh2->arg[0], "env") == 0)
			write_env(sh2);
		else if (ft_strcmp(sh2->arg[0], "setenv") == 0)
			ft_setenv(sh2);
		else if (ft_strcmp(sh2->arg[0], "unsetenv") == 0)
			ft_unsetenv(sh2);
		else if (ft_strcmp(sh2->arg[0], "cd") == 0)
			ft_cd(sh2);
		else if (ft_strcmp(sh2->arg[0], "pwd") == 0)
			ft_get(sh2);
		else if (ft_strchr(sh2->arg[0], '/'))
			check_the_check(sh2, sh2->arg[0], sh2->arg, sh2->env_cpy);
		else if (sh2->arg[0])
			check_path(sh2->path, sh2->arg, sh2);
		else
			ft_putendl("Command not found.");
	}
	sh2->cmd ? free(sh2->cmd) : 0;
	return (0);
}
