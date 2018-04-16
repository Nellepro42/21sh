/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_21sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:53:06 by neprocur          #+#    #+#             */
/*   Updated: 2017/07/18 04:07:03 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_21SH_H
# define FT_21SH_H
# define BUFF_SIZE 9999

# include "libft/libft.h"
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <termios.h>
#include <termcap.h>

# define UPD_ENV_PATH "PATH=/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt"

typedef struct			s_shell
{
	int					k;
	int					b;
	char				*cmd;
	char				*buf;
	char				*home;
	char				*pwd;
	char				*oldpwd;
	char				**path;
	char				**arg;
	char				**env_cpy;
	char				**tabl;
}						t_shell;

int						get_next_line(int const fd, char **line);
void					sig_manage(void);
void					ft_init_env(t_shell *sh2, char **env);
char					**epur_cmd(char *cmd);
char					**split_env(t_shell *sh2);
void					prompt(void);
int						tablen(char **tab);
void					ft_update_env(t_shell *sh2);
int						ft_setenv_option(t_shell *sh2, int i, int n);
int						ft_setenv_equal(t_shell *sh2);
void					ft_setenv_option2(t_shell *sh2, int n);
void					ft_setenv(t_shell *sh2);
int						ft_unsetenv(t_shell *sh2);
int						ft_builtins(t_shell *sh2, char **arg);
void					write_env(t_shell *sh2);
void					ft_get(t_shell *sh2);
void					ft_next(t_shell *sh2);
int						ft_while(t_shell *sh1, char **env, char **av);
int						ft_cd(t_shell *sh2);
int						ft_next2(t_shell *sh2);
char					*env_to_str(t_shell *sh2, char const *str);
void					ft_actualise(t_shell *sh2, char *dir);
void					ft_new_var_cd(t_shell *sh2, char *var);
int						check_the_check(t_shell *sh2, char *cmd_test, char **arg, char **path);
int						check_path(char **path, char **arg, t_shell *sh2);
int						check_path_two(char **path, char **arg, t_shell *sh2, char *cmd_test);
int						check_command(char *cmd_test, int *boul, char **arg, t_shell *sh2);
void					ft_args(t_shell *sh2);
void					ft_move_pwd(char *pwd, t_shell *sh2);
void					ft_move_oldpwd(char *oldpwd, t_shell *sh2);
void					ft_move_cd1(t_shell *sh2, char *pwd);
int						ft_search(t_shell *sh2);
int						ft_search_i(t_shell *sh2);
void					ft_swap_pwd(t_shell *sh2);
int						ft_access(char *path);
void					setenv_cd(t_shell *sh2, char *arg);
int						ft_search2(t_shell *sh2, char *var);
void					ft_setenv_cd_cd(char *arg, t_shell *sh2, char *buf);
void					ft_setenv_cd_option(t_shell *sh2, int i, int n);

#endif
