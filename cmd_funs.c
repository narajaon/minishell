/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_funs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:51:52 by narajaon          #+#    #+#             */
/*   Updated: 2017/11/02 18:46:17 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int			echo_cmd(t_sh *sh_env, char **bin_path)
{
	int		i;

	i = 0;
	bin_path = (char **)bin_path;
	sh_env->input.split_in = ft_arg_split(&sh_env->input.user_in[4],
			&sh_env->input.input_lst);
	ft_format_tab_content(sh_env->input.split_in, &format_input);
	while (sh_env->input.split_in[i] != NULL)
	{
		ft_dprintf(g_fd_ou, "%s", sh_env->input.split_in[i++]);
		if (sh_env->input.split_in[i])
			ft_dprintf(g_fd_ou, " ");
	}
	if (g_fd_ou == STDO)
		ft_putstr_fd("\n", g_fd_ou);
	free_tab_str(&sh_env->input.split_in);
	return (0);
}

int			export_cmd(t_sh *sh_env, char **bin_path)
{
	return (0);
}

int			setenv_cmd(t_sh *sh_env, char **bin_path)
{
	int		i;
	char	**arg;

	i = 0;
	arg = NULL;
	if (is_valid_setenv_arg(&sh_env->input.user_in[6], &i) == FALSE)
	{
		return (exit_error(SETENV_INVAL,
					&sh_env->input.user_in[6], "setenv", -1));
	}
	if (setenv_has_args(&sh_env->input.user_in[6]) == FALSE)
		return (env_cmd(sh_env, bin_path));
	sh_env->input.split_in = ft_arg_split(&sh_env->input.user_in[6],
			&sh_env->input.input_lst);
	if (sh_env->input.split_in[0] != NULL &&
			sh_env->input.split_in[1] != NULL &&
			sh_env->input.split_in[2] != NULL)
		return (exit_error(EX_ARG, sh_env->input.split_in[2], "setenv", -1));
	add_var_to_env(sh_env->input.split_in, &sh_env->cmd_env.env_list);
	update_env_tab(sh_env);
	return (0);
}

int			unsetenv_cmd(t_sh *sh_env, char **bin_path)
{
	int		i;

	i = 0;
	bin_path = (char **)bin_path;
	sh_env->input.split_in = ft_arg_split(&sh_env->input.user_in[8],
			&sh_env->input.input_lst);
	if (sh_env->input.split_in[0] == NULL)
		return (exit_error(LES_ARG, "", "unsetenv", -1));
	while (sh_env->input.split_in[i])
	{
		ft_lstpop(&sh_env->cmd_env.env_list, &is_env_var,
				sh_env->input.split_in[i]);
		i++;
	}
	update_env_tab(sh_env);
	return (0);
}

int			env_cmd(t_sh *sh_env, char **bin_path)
{
	t_list	*tmp_env;
	int		i;

	i = 0;
	tmp_env = NULL;
	bin_path = (char **)bin_path;
	sh_env->input.split_in = ft_arg_split(sh_env->input.user_in,
			&sh_env->input.input_lst);
	if (sh_env->input.split_in[1] == 0)
		ft_lstiter(sh_env->cmd_env.env_list, &ft_print_lst);
	else
		apply_env_opt(sh_env->input.split_in, bin_path, sh_env);
	return (0);
}
