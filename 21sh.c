/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 01:44:06 by neprocur          #+#    #+#             */
/*   Updated: 2017/07/17 01:08:45 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void		ft_init_env(t_shell *sh2, char **env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!env || !*env)
	{
		ft_update_env(sh2);
		return ;
	}
	sh2->env_cpy = (char **)malloc(sizeof(char *) * (tablen(env) + 2));
	while (env[i])
	{
		if (ft_strncmp(env[i], "HOME=", 4) == 0)
			sh2->home = ft_strdup(env[i]);
		sh2->env_cpy[i] = ft_strdup(env[i]);
		i++;
	}
	sh2->env_cpy[i] = NULL;
}

void		sig_manage(void)
{
	int		i;

	i = 1;
	while (i <= 31)
	{
		signal(i, SIG_IGN);
		i++;
	}
}

int			main(int ac, char **av, char **env)
{
	t_shell		*sh2;
	int			i;

	i = 0;
	sig_manage();
	sh2 = (t_shell *)malloc(sizeof(t_shell));
	ft_init_env(sh2, env);
	ft_while(sh2, sh2->env_cpy, av);
	return (0);
}
