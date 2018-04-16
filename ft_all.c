/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:46:56 by neprocur          #+#    #+#             */
/*   Updated: 2017/07/17 02:01:29 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void				ft_args(t_shell *sh2)
{
	char			**args;

	args = (char **)malloc(sizeof(char *) * 4);
	args[0] = ft_strdup("cd");
	args[1] = ft_strdup("PWD");
	args[2] = ft_strdup(sh2->home);
	args[3] = NULL;
	sh2->arg = args;
	ft_setenv(sh2);
	free(args);
}

void				ft_move_pwd(char *pwd, t_shell *sh2)
{
	char			**args;

	args = (char **)malloc(sizeof(char *) * 4);
	args[0] = ft_strdup("change directory");
	args[1] = ft_strdup("PWD");
	args[2] = ft_strdup(pwd);
	args[3] = NULL;
	sh2->arg = args;
	setenv_cd(sh2, *sh2->arg);
	free(args[0]);
	free(args[1]);
	free(args[2]);
	free(args);
}

void				ft_move_oldpwd(char *oldpwd, t_shell *sh2)
{
	char			**args;

	args = (char **)malloc(sizeof(char *) * 4);
	args[0] = ft_strdup("change directory");
	args[1] = ft_strdup("OLDPWD");
	args[2] = ft_strdup(oldpwd);
	args[3] = NULL;
	sh2->arg = args;
	setenv_cd(sh2, *sh2->arg);
	free(args[0]);
	free(args[1]);
	free(args[2]);
	free(args);
}

void				ft_move_cd1(t_shell *sh2, char *pwd)
{
	char			buff[256];
	char			**tmp;

	tmp = NULL;
	getcwd(buff, 256);
	tmp = sh2->arg;
	ft_move_pwd(buff, sh2);
	ft_move_oldpwd(&pwd[4], sh2);
	sh2->arg = tmp;
}
