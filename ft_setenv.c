/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 04:03:34 by neprocur          #+#    #+#             */
/*   Updated: 2017/07/17 02:15:18 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

int		ft_unsetenv(t_shell *sh2)
{
	int		i;
	int		j;

	j = 1;
	sh2->k = 0;
	if (!sh2->arg[0])
		return (-1);
	while (sh2->arg[j])
	{
		i = 0;
		sh2->k = 0;
		sh2->tabl = (char **)malloc(sizeof(char *) * (tablen(sh2->env_cpy)));
		while (sh2->env_cpy[i])
		{
			if (ft_strncmp(sh2->env_cpy[i], sh2->arg[j],
						ft_strlen(sh2->arg[j])) != 0)
				sh2->tabl[sh2->k++] = ft_strdup(sh2->env_cpy[i]);
			i++;
		}
		j++;
		sh2->tabl[sh2->k] = NULL;
		free(sh2->env_cpy);
		sh2->env_cpy = sh2->tabl;
	}
	return (0);
}

void		ft_setenv_option2(t_shell *sh2, int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		sh2->tabl = sh2->env_cpy;
		sh2->env_cpy = (char**)malloc(sizeof(char*) * (tablen(sh2->tabl) + 2));
		while (sh2->tabl[i])
		{
			sh2->env_cpy[i] = ft_strdup(sh2->tabl[i]);
			i++;
		}
		sh2->env_cpy[i] = (char *)malloc(sizeof(char) * ft_strlen(sh2->arg[1])
				+ ft_strlen(sh2->arg[2] + 2));
		ft_strcpy(sh2->env_cpy[i], sh2->arg[1]);
		ft_strcat(sh2->env_cpy[i], "=");
		ft_strcat(sh2->env_cpy[i], sh2->arg[2]);
		i++;
		sh2->env_cpy[i] = NULL;
	}
}

int			ft_setenv_equal(t_shell *sh2)
{
	if (ft_strchr(sh2->arg[1], '='))
	{
		ft_putendl("setenv: Syntax Error.");
		return (-1);
	}
	return (0);
}

int			ft_setenv_option(t_shell *sh2, int i, int n)
{
	ft_setenv_equal(sh2);
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
	}
	if (sh2->arg[3])
	{
		ft_putendl("Too many arguments");
		return (-1);
	}
	else
		ft_setenv_option2(sh2, n);
	return (0);
}

void		ft_setenv(t_shell *sh2)
{
	int		i;
	int		n;

	i = 0;
	n = ft_search(sh2);
	if (sh2->arg[0] && !sh2->arg[1])
		write_env(sh2);
	else if (sh2->arg[1] && !sh2->arg[2])
	{
		if (n == -1)
			ft_next(sh2);
	}
	else
		ft_setenv_option(sh2, i ,n);
}
