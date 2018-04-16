/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 04:12:28 by neprocur          #+#    #+#             */
/*   Updated: 2017/07/17 02:17:48 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

char			*env_to_str(t_shell *sh1, char const *str)
{
	char		**env;
	int			i;

	i = 0;
	env = NULL;
	if (sh1 && str)
	{
		if ((env = sh1->env_cpy))
		{
			while (env[i])
			{
				if (!ft_strncmp(env[i], str, ft_strlen(str)))
					return (env[i]);
				i++;
			}
		}
	}
	return (NULL);
}

void			ft_new_var_cd(t_shell *sh2, char *var)
{
	int			i;
	int			n;

	i = 0;
	sh2->tabl = sh2->env_cpy;
	sh2->env_cpy = (char**)malloc(sizeof(char*) * (tablen(sh2->tabl) + 2));
	while (sh2->tabl[i] != NULL)
	{
		sh2->env_cpy[i] = ft_strdup(sh2->tabl[i]);
		i++;
	}
	sh2->env_cpy[i] = ft_strdup(var);
	i++;
	sh2->env_cpy[i] = NULL;
}

void			ft_actualise(t_shell *sh2, char *dir)
{
	char		pathpwd[256];
	char		*tmp;
	int			ret;
	int			old;
	int			pwd;

	old = ft_search2(sh2, "OLDPWD");
	pwd = ft_search2(sh2, "PWD");
	getcwd(pathpwd, 256);
	tmp = ft_strjoin("OLDPWD=", pathpwd);
	if (ft_access(dir) == 0)
	{
		chdir(dir);
		if (old != -1)
			sh2->env_cpy[ft_search2(sh2, "OLDPWD")] = tmp;
		else
			ft_new_var_cd(sh2, tmp);
		getcwd(pathpwd, 256);
		if (pwd != -1)
			sh2->env_cpy[ft_search2(sh2, "PWD")] = ft_strjoin("PWD=", pathpwd);
		else
			ft_new_var_cd(sh2, ft_strjoin("PWD=", pathpwd));
	}
}

int				ft_next2(t_shell *sh1)
{
	ft_putendl("cd: Too many arguments.");
	return (-1);
}

int				ft_cd(t_shell *sh1)
{
	char		*home;
	char		*pwd;
	char		*old_pwd;

	if (sh1->arg[0] && sh1->arg[1] && sh1->arg[2])
		ft_next2(sh1);
	if (!sh1->arg[1] || sh1->arg[1][0] == '~')
	{
		if ((home = env_to_str(sh1, "HOME=")) != NULL)
			ft_actualise(sh1, home + 5);
		else
			ft_actualise(sh1, &(sh1->home[5]));
	}
	else if (sh1->arg[1] && !ft_strcmp(sh1->arg[1], "-"))
	{
		if ((old_pwd = env_to_str(sh1, "OLDPWD=")) != NULL)
			ft_actualise(sh1, old_pwd + 7);
		else
			ft_putendl("no oldpwd");
	}
	else if (sh1->arg[1] && *sh1->arg[1])
		ft_actualise(sh1, sh1->arg[1]);
	return (0);
}
