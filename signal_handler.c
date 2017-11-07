/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:52:22 by narajaon          #+#    #+#             */
/*   Updated: 2017/11/05 16:07:35 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_bool		jump_loop(void)
{
	if (g_loop == FALSE)
	{
		g_loop = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

void		sighandler(int sigval)
{
	ft_printf("\n");
	if (sigval == SIGINT)
	{
		if (g_cur_pid > 0)
			ft_dprintf(g_fd_ou, "Process [%d] interrupted\n", g_cur_pid);
		else
			g_loop = FALSE;
	}
	if (sigval == SIGSEGV)
	{
		ft_dprintf(g_fd_ou, "/!\\ Segmentation fault, not funny\n");
		flush_sh_env(g_env_ptr);
		exit(1);
	}
}

void		sig_intercepter(void)
{
	struct sigaction	sa_struct;

	ft_bzero(&sa_struct, sizeof(sa_struct));
	sa_struct.sa_handler = &sighandler;
	if (sigaction(SIGINT, &sa_struct, NULL) < 0)
		ft_printf("[sigaction] failed to catch SIGINT");
	signal(SIGSEGV, &sighandler);
}
