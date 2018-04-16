/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 03:27:34 by neprocur          #+#    #+#             */
/*   Updated: 2017/07/17 02:05:01 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void				ft_next(t_shell *sh2)
{
	int				i;

	i = 0;
	sh2->tabl = sh2->env_cpy;
	sh2->env_cpy = (char **)malloc(sizeof(char *) * ( tablen(sh2->tabl) + 2));
	while (sh2->tabl[i])
	{
		sh2->env_cpy[i] = ft_strdup(sh2->tabl[i]);
		i++;
	}
	sh2->env_cpy[i] = ft_strnew(ft_strlen(sh2->arg[1]) + 2);
	ft_strcpy(sh2->env_cpy[i], sh2->arg[1]);
	ft_strcat(sh2->env_cpy[i], "=");
	i++;
	sh2->env_cpy[i] = NULL;
}

int					ft_while(t_shell *sh1, char **env, char **av)
{
	while (42)
	{
		ft_update_env(sh1);
		prompt();
		if ((get_next_line(0, &(sh1->cmd))) == 0)
		{
			ft_putendl("exit");
			exit(-1);
		}
		sh1->path = split_env(sh1);
		if (sh1->cmd)
		{
			sh1->arg = epur_cmd(sh1->cmd);
			if (sh1->arg[0] != NULL)
			{
				if (ft_strcmp(sh1->arg[0], "exit") == 0)
				{
					ft_putendl("exit");
					return (0);
				}
				ft_builtins(sh1, sh1->arg);
			}
		}
	}
	return (0);
}
