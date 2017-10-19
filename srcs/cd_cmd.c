/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:51:49 by narajaon          #+#    #+#             */
/*   Updated: 2017/10/18 14:06:07 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void		update_env_tab(t_sh *sh_env)
{
	char	**to_free;
	char	**to_free2;

	to_free = ft_list_to_tab(&sh_env->cmd_env.env_list);
	to_free2 = ft_tab_dup(to_free);
	free_tab_str(&to_free);
	ft_lstdel(&sh_env->cmd_env.env_list, &del_list);
	free_tab_str(&sh_env->cmd_env.env_tab);
	sh_env->cmd_env.env_tab = to_free2;
	sh_env->cmd_env.env_list = ft_tab_to_list(to_free2);
}

char		**fill_env_var(char *var_name, char *var_value)
{
	char	**arg;

	arg = ft_memalloc(sizeof(char *) * 3);
	arg[0] = ft_strdup(var_name);
	arg[1] = ft_strdup(var_value);
	arg[2] = 0;
	return (arg);
}

void		update_path(t_sh *sh_env, char *cur_dir)
{
	char	**arg;

	getcwd(sh_env->cur_dir, PATH_MAX + 1);
	arg = fill_env_var("PWD", sh_env->cur_dir);
	add_var_to_env(arg, &sh_env->cmd_env.env_list);
	free_tab_str(&arg);
	update_env_tab(sh_env);
	arg = fill_env_var("OLDPWD", sh_env->prev_dir);
	add_var_to_env(arg, &sh_env->cmd_env.env_list);
	free_tab_str(&arg);
	update_env_tab(sh_env);
}

int			cd_cmd(t_sh *sh_env, char **bin_path)
{
	char	*cur_dir;

	bin_path = (char **)bin_path;
	sh_env->input.split_in = ft_arg_split(&sh_env->input.user_in[2],
			&sh_env->input.input_lst);
	if (sh_env->input.split_in[0] != NULL &&
			sh_env->input.split_in[1] != NULL)
		return (exit_error(CD_INVAL, sh_env->input.split_in[1], "cd", -1));
	if (sh_env->input.split_in[0] != NULL)
	{
		if (ft_strcmp(sh_env->input.split_in[0], "-") == 0 ||
			ft_strcmp(sh_env->input.split_in[0], "-1") == 0)
			cur_dir = sh_env->prev_dir;
		else
			cur_dir = sh_env->input.split_in[0];
	}
	else
		cur_dir = get_var_val(&sh_env->cmd_env, "HOME");
	if (chdir(cur_dir) < 0)
		return (exit_error(WRONG_TYPE, cur_dir, "cd", -1));
	ft_strcpy(sh_env->prev_dir, sh_env->cur_dir);
	update_path(sh_env, cur_dir);
	return (0);
}
