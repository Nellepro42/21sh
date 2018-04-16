/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 02:21:12 by neprocur          #+#    #+#             */
/*   Updated: 2017/07/18 04:02:32 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void		ft_update_env(t_shell *sh2)
{
	if (!sh2->env_cpy || !sh2->env_cpy[0])
	{
		sh2->env_cpy = malloc(sizeof(char *) * 2);
		sh2->env_cpy[0] = ft_strdup(UPD_ENV_PATH);
		sh2->env_cpy[1] = NULL;
	}
}

int			tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void		prompt(void)
{
	ft_putstr("\033[31m [ Nelle 21sh ]$> \033[0m");
}

char			**split_env(t_shell *sh2)
{
	char		**tab;
	int			i;

	i = 0;
	tab = NULL;
	while (sh2->env_cpy[i])
	{
		if (ft_strncmp("PATH=", sh2->env_cpy[i], 5) == 0)
		{
			tab = ft_strsplit(&sh2->env_cpy[i][5], ':');
			break ;
		}
		i++;
	}
	return (tab);
}

char		**epur_cmd(char *cmd)
{
	char	**new;
	int		i;
	int		point;

	ft_strtrim(cmd);
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\t')
			cmd[i] = ' ';
		if (cmd[i] == ';')
			point = 1;
		i++;
	}
	new = ft_strsplit(cmd, ' ');
	return (new);
}
