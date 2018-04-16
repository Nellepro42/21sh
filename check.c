/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 18:16:11 by neprocur          #+#    #+#             */
/*   Updated: 2017/07/17 01:14:30 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

int				check_backslash(t_shell *sh2, int *boul, char **arg)
{
	if ((sh2->arg[0][0] == '/') && (access(sh2->arg[0], F_OK) == 0))
	{
		*boul = 1;
		if ((access(sh2->arg[0], X_OK) == 0))
		{
			check_the_check(sh2, sh2->arg[0], arg, sh2->path);
			return (0);
		}
	}
	return (-1);
}

int				check_command(char *cmd_test, int *boul, char **arg,
		t_shell *sh2)
{
	if (access(cmd_test, F_OK) == 0)
	{
		*boul = 1;
		if (access(cmd_test, X_OK) == 0)
		{
			check_the_check(sh2, cmd_test, arg, sh2->path);
			return (0);
		}
	}
	return (-1);
}

int				check_path_two(char **path, char **arg, t_shell *sh2,
		char *cmd_test)
{
	int			i;
	int			boul;

	i = 0;
	boul = 0;
	while (sh2->path[i])
	{
		cmd_test = ft_strdup(sh2->path[i]);
		cmd_test = ft_strjoin(cmd_test, "/");
		cmd_test = ft_strjoin(cmd_test, arg[0]);
		if (check_backslash(sh2, &boul, arg) == 0)
			break ;
		if (check_command(cmd_test, &boul, arg, sh2) == 0)
			break ;
		cmd_test ? free(cmd_test) : 0;
		i++;
	}
	if (boul == 0)
	{
		ft_putstr(sh2->arg[0]);
		ft_putendl(": Command not found.");
	}
	return (0);
}

int				check_path(char **path, char **arg, t_shell *sh2)
{
	char		*cmd_test;

	path = path;
	if (sh2->arg[0][0] == '\0')
		return (0);
	if (sh2->path != NULL)
	{
		check_path_two(path, arg, sh2, cmd_test);
	}
	return (0);
}

int				check_the_check(t_shell *sh2, char *cmd_test, char **arg,
		char **path)
{
	pid_t		pid;

	pid = fork();
	path = path;
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (!(execve(cmd_test, arg, sh2->env_cpy)))
			ft_putendl("Command not found.");
	}
	else
		wait(NULL);
	return (1);
}
