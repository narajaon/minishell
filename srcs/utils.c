/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:52:24 by narajaon          #+#    #+#             */
/*   Updated: 2017/10/18 13:29:52 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int			exit_error(int error, char *bad_input, char *cmd_name, int ret)
{
	g_errno = error;
	if (bad_input == NULL || *bad_input == '\0')
	{
		ft_dprintf(g_fd_err, "%s: %s : %s\n", cmd_name,
				g_sh_error[g_errno].err_str, bad_input);
	}
	else
	{
		ft_dprintf(g_fd_err, "%s: %s\n", cmd_name,
				g_sh_error[g_errno].err_str);
	}
	return (g_cmd_ret = ret);
}

void		del_list(void *content, size_t size)
{
	content = (void*)content;
	size = (size_t)size;
}

char		**ft_format_tab_content(char **arg, void (*fmt)())
{
	char	**tab;

	tab = arg;
	while (*tab)
	{
		fmt(&*tab);
		tab++;
	}
	return (arg);
}

char		*get_var_val(t_shenv *cmd_env, char *var)
{
	t_list		*tmp;
	char		*home;

	tmp = cmd_env->env_list;
	while (tmp)
	{
		if (is_env_var(tmp->content, var))
			break ;
		tmp = tmp->next;
	}
	if (tmp != NULL)
	{
		home = tmp->content;
		return (&home[ft_strlen(var) + 1]);
	}
	return (0);
}

void		flush_sh_env(t_sh *env)
{
	free_tab_str(&env->input.split_in);
	free_str(&env->input.user_in);
	free_tab_str(&env->cmd_env.bin_path);
	ft_lstdel(&env->input.input_lst, &del_list);
	g_errno = 0;
	g_cmd_ret = 0;
	g_cur_pid = 0;
	g_user_input = NULL;
}
