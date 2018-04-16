/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:49:43 by neprocur          #+#    #+#             */
/*   Updated: 2017/07/17 01:10:44 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

int				ft_access(char *path)
{
	if (access(path, F_OK) == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(path);
	}
	else if ((access(path, X_OK | R_OK)) == -1)
	{
		ft_putstr("cd : permission denied: ");
		ft_putendl(path);
	}
	return (0);
}

void				ft_swap_pwd(t_shell *sh2)
{
	int				i;
	char			oldpwd[256];
	char			pwd[256];
	char			**tmp;

	i = 0;
	while (sh2->env_cpy[i])
	{
		if (ft_strncmp(sh2->env_cpy[i], "OLDPWD=", 6) == 0)
			ft_strcpy(oldpwd, sh2->env_cpy[i]);
		if (ft_strncmp(sh2->env_cpy[i], "PWD=", 3) == 0)
			ft_strcpy(pwd, sh2->env_cpy[i]);
		i++;
	}
	if ((chdir(&oldpwd[7])) != -1)
	{
		tmp = sh2->arg;
		ft_move_pwd(&oldpwd[7], sh2);
		ft_move_oldpwd(&pwd[4], sh2);
		sh2->arg = tmp;
	}
}

int					ft_search_i(t_shell *sh2)
{
	int				i;

	i = 0;
	if (sh2->env_cpy)
	{
		while (sh2->env_cpy[i])
		{
			if ((ft_strncmp(sh2->env_cpy[i], sh2->arg[0],
							ft_strlen(sh2->arg[0])) == 0) &&
					(sh2->env_cpy[i][ft_strlen(sh2->arg[0])] == '='))
				return (i);
			i++;
		}
	}
	return (-1);
}

int					ft_search(t_shell *sh2)
{
	int				i;

	i = 0;
	if (sh2->env_cpy)
	{
		while (sh2->env_cpy[i])
		{
			if ((ft_strncmp(sh2->env_cpy[i], sh2->arg[1],
							ft_strlen(sh2->arg[1])) == 0) &&
					(sh2->env_cpy[i][ft_strlen(sh2->arg[1])] == '='))
				return (i);
			i++;
		}
	}
	return (-1);
}
