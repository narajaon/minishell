/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 10:48:13 by narajaon          #+#    #+#             */
/*   Updated: 2018/01/31 15:54:39 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			exit_cmd(t_sh *sh_env, char **bin_path)
{
	bin_path = (char **)bin_path;
	flush_sh_env(sh_env);
	exit(1);
	return (0);
}

t_bool		is_binary_file(char *bin_name)
{
	if (ft_strchr(bin_name, '/') != 0)
		return (TRUE);
	return (FALSE);
}

int			exec_cmd(t_sh *sh_env, char **bin_path)
{
	char	*path;

	path = NULL;
	if (sh_env->input.user_in == NULL)
	{
		flush_sh_env(sh_env);
		return (0);
	}
	sh_env->input.split_in = ft_arg_split(sh_env->input.user_in,
			&sh_env->input.input_lst);
	if (sh_env->input.split_in[0] == NULL)
		return (0);
	ft_format_tab_content(sh_env->input.split_in, &format_input);
	path = check_bin(bin_path, &sh_env->proc, &sh_env->input);
	if (path == NULL)
	{
		if ((is_binary_file(sh_env->input.split_in[0]) == TRUE) &&
			(is_valid_path(sh_env->input.split_in[0]) == TRUE))
		{
			path = sh_env->input.split_in[0];
		}
		else
			return (exit_error(NOT_A_CMD, sh_env->input.cmd_name, "my_sh", -1));
	}
	execve(path, sh_env->input.split_in, sh_env->cmd_env.env_tab);
	return (0);
}
