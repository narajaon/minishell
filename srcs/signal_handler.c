/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:52:22 by narajaon          #+#    #+#             */
/*   Updated: 2017/10/19 08:04:59 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void		sighandler(int sigval)
{
	if (sigval == SIGINT)
	{
		if (g_cur_pid > 0)
		{
			ft_dprintf(g_fd_ou, " %C Process [%d] terminated\n", EMJ_ARRW, g_cur_pid);
			kill(g_cur_pid, SIGINT);
		}
	}
	if (sigval == SIGSEGV)
	{
		ft_dprintf(g_fd_ou, "\n/!\\ Segmentation fault, not funny\n");
		exit(1);
	}
}

void		sig_intercepter(void)
{
	signal(SIGINT, &sighandler);
	signal(SIGSEGV, &sighandler);
}
