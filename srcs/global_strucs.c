/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_strucs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:52:10 by narajaon          #+#    #+#             */
/*   Updated: 2017/10/19 18:08:32 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int					g_errno;
int					g_cmd_ret;
int					g_fd_ou;
int					g_fd_in;
int					g_fd_err;
pid_t				g_cur_pid;
char				*g_user_input;

const t_shcmd		g_sh_struct[PRC_NB + 1] =
{
	{"echo", ECHO, &echo_cmd},
	{"cd", CD, &cd_cmd},
	{"setenv", SET, &setenv_cmd},
	{"export", EXP, &export_cmd},
	{"unsetenv", USET, &unsetenv_cmd},
	{"env", ENV, &env_cmd},
	{"exit", EXT, &exit_cmd},
	{"", -1, NULL}
};

const t_sherror		g_sh_error[NB_ERR + 1] =
{
	{"command not found", NOT_A_CMD},
	{"couldn't open directory", ERRDIR},
	{"error during fork process", PID},
	{"no such file or directory", WRONG_TYPE},
	{"not valid in this context", INVALID_CMD},
	{"variable name must contain alphanumeric characters", SETENV_INVAL},
	{"string not in pwd", CD_INVAL},
	{"too many arguments.", EX_ARG},
	{"too few arguments.", LES_ARG},
	{"illegal option", USAGE},
	{"permission denied", NO_PERM},
	{"variable not initiated", VAR_UNSET},
	{"", NB_ERR}
};

const t_sighand		g_sig_msg[NB_SIG + 1] =
{
	{"process interrupted", MYSIG_INT},
	{"", NB_SIG}
};

const t_schar		g_spec_char[SCHAR_NB] =
{
	{"\\a", '\a'},
	{"\\f", '\f'},
	{"\\n", '\n'},
	{"\\b", '\b'},
	{"\\r", '\r'},
	{"\\t", '\t'},
	{"\\v", '\v'},
	{"\\\\", '\\'},
	{"\\'", '\''},
	{"\\\"", '\"'},
	{"", 0},
};
