/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_local_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:52:15 by narajaon          #+#    #+#             */
/*   Updated: 2017/10/19 08:08:40 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_bool		is_var_type(char *str)
{
	int		i;

	i = 0;
	return (FALSE);
}

void		fill_var_struct(char *str, t_local *var)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	var->name = ft_strsub(str, 0, i);
	if (str[i] == '\0')
	{
		var->has_equ = FALSE;
		return ;
	}
	i++;
	var->val = ft_strdup(&str[i]);
	var->has_equ = TRUE;
}

void			init_env(t_sh *sh_env, char **env)
{
	char		pwd[PATH_MAX];
	char		path[PATH_MAX];
	char		**to_free;

	to_free = NULL;
	if (env == NULL || *env == NULL)
	{
		getcwd(pwd, PATH_MAX + 1);
		ft_strcpy(path, "PWD=");
		ft_strcat(path, pwd);
		env = fill_env_var("HOME=/Users/narajaon", path);
		to_free = env;
	}
	sh_env->cmd_env.env_tab = ft_tab_dup(env);
	sh_env->cmd_env.env_list = ft_tab_to_list(sh_env->cmd_env.env_tab);
	free_tab_str(&to_free);
}
