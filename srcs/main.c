/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 10:46:09 by narajaon          #+#    #+#             */
/*   Updated: 2017/10/19 08:08:09 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void			fork_process(int proc_id, int (*cmd)(),
		t_sh *sh_env, char **bin_path)
{
	int			status;

	if (proc_id >= 0)
	{
		status = cmd(sh_env, bin_path);
		return ;
	}
	if ((g_cur_pid = fork()) == 0)
	{
		status = exec_cmd(sh_env, bin_path);
		exit(status);
	}
	if ((waitpid(g_cur_pid, &status, 0) < 0))
		exit_error(PID, 0, "my_sh", -1);
}

void			exec_sh(t_sh *sh_env)
{
	int			(*cmd)();
	char		**bin_path;
	char		*cur_dir;

	cmd = NULL;
	cur_dir = get_cur_dir(sh_env->cur_dir);
	ft_strcpy(sh_env->prev_dir, sh_env->cur_dir);
	while (TRUE)
	{
		sh_env->cmd_env.bin_path = get_env_path(sh_env->cmd_env.env_tab);
		ft_printf("%s%s%s %C ", KCYN, cur_dir, KNRM, EMJ_ARRW);
		get_input(g_fd_in, &sh_env->input);
		sh_env->proc.proc_id =
			get_proc_index(sh_env->input.cmd_name, g_sh_struct);
		if (sh_env->proc.proc_id >= 0)
			cmd = g_sh_struct[sh_env->proc.proc_id].fun_ptr;
		fork_process(sh_env->proc.proc_id, cmd,
				sh_env, sh_env->cmd_env.bin_path);
		cur_dir = get_cur_dir(sh_env->cur_dir);
		flush_sh_env(sh_env);
	}
}

void			ft_usage(int ac, char **av)
{
	if (ac == 2 && ft_strcmp(av[1], "-c") == 0)
		write(g_fd_ou, "\e[1;1H\e[2J", 11);
	else if (ac == 2 && ft_strcmp(av[1], "-i") == 0)
		ft_printf("-c : fullscreen mode\n");
}

int				main(int ac, char **av, char **env)
{
	t_sh		sh_env;
	char		**local_env;
	int			i;

	i = 0;
	g_fd_ou = STDO;
	g_fd_in = STDI;
	g_fd_err = STDE;
	g_cmd_ret = 0;
	sh_env.input.user_in = NULL;
	sh_env.input.input_lst = NULL;
	sh_env.cmd_env.env_list = NULL;
	sh_env.cmd_env.bin_path = NULL;
	setlocale(LC_ALL, "");
	sig_intercepter();
	ft_usage(ac, av);
	init_env(&sh_env, env);
	exec_sh(&sh_env);
	free_tab_str(&local_env);
	return (0);
}
