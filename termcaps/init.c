/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 23:23:40 by neprocur          #+#    #+#             */
/*   Updated: 2017/07/26 02:31:58 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_21sh.h"

init_terminal_data()
{
	char		*termtype = getenv ("TERM");
	int			success;

	if (termtype == 0)
	{
		ft_putstr("Specifiez un type de terminal avec 'setenv TERM <yourtype>'.\n");
		return (-1);
	}
	success = tgetent (term_buffer, term);
	if (success < 0)
	{
		ft_putstr("Impossible d'acceder a la base de donnees termcap." \n);
		return (-1);
	}
	if (success == 0)
	{
		ft_putstr("Type de terminal '%s' n'est pas defini. \n", term);
		return (-1);
	}
}


