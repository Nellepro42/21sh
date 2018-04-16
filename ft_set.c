/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 23:15:26 by neprocur          #+#    #+#             */
/*   Updated: 2017/07/17 02:05:49 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void		ft_setenv_cd_option(t_shell *sh2, int i, int n)
{
	if (sh2->arg[1] && sh2->arg[2])
	{
		if (n >= 0)
		{
			i = n;
			free(sh2->env_cpy[i]);
			sh2->env_cpy[i] = (char *)malloc(sizeof(char) *
					(ft_strlen(sh2->arg[1]) + (ft_strlen(sh2->arg[2]) + 2)));
			ft_strcpy(sh2->env_cpy[i], sh2->arg[1]);
			ft_strcat(sh2->env_cpy[i], "=");
			ft_strcat(sh2->env_cpy[i], sh2->arg[2]);
			i++;
		}
		else
		{
			sh2->env_cpy[i] = ft_strnew(ft_strlen(sh2->arg[1]) +
					(ft_strlen(sh2->arg[2] + 2)));
			ft_strcpy(sh2->env_cpy[i], sh2->arg[1]);
			ft_strcat(sh2->env_cpy[i], "=");
			ft_strcat(sh2->env_cpy[i], sh2->arg[2]);
			i++;
			sh2->env_cpy[i] = NULL;
		}
	}
}

void		ft_setenv_cd_cd(char *arg, t_shell *sh2, char *buf)
{
	int		i;

	i = 0;
	while (sh2->env_cpy[i])
		i++;
	sh2->env_cpy[i] = ft_strnew(ft_strlen(arg) + 8);
	ft_strcat(sh2->env_cpy[i], "OLDPWD=");
	ft_strcat(sh2->env_cpy[i], getcwd(buf, 256));
	i++;
	sh2->env_cpy[i] = NULL;
}

int			ft_search2(t_shell *sh2, char *var)
{
	int		i;

	i = 0;
	if (sh2->env_cpy)
	{
		while (sh2->env_cpy[i])
		{
			if (ft_strncmp(sh2->env_cpy[i], var, ft_strlen(var)) == 0 &&
					(sh2->env_cpy[i][ft_strlen(var)] == '='))
				return (i);
			i++;
		}
	}
	return (-1);
}

void		setenv_cd(t_shell *sh2, char *arg)
{
	int		i;
	int		n_old;
	int		n_pwd;
	char	*buf;

	n_old = ft_search2(sh2, "OLDPWD");
	n_pwd = ft_search2(sh2, "PWD");
	if (n_old == -1)
		ft_setenv_cd_cd(arg, sh2, buf);
	else
		ft_strcat(sh2->env_cpy[n_old] + 7, env_to_str(sh2, "PWD="));
	i = 0;
	if (n_pwd == -1)
	{
		while (sh2->env_cpy[i])
			i++;
		sh2->env_cpy[i] = ft_strnew(ft_strlen(arg) + 8);
		ft_strcat(sh2->env_cpy[i], "PWD=");
		ft_strcat(sh2->env_cpy[i], arg);
		i++;
		sh2->env_cpy[i] = NULL;
	}
	else
		ft_strcat(sh2->env_cpy[n_pwd] + 4, arg);
	ft_setenv_cd_option(sh2, i, n_old);
}
