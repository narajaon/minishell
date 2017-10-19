/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_funs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:52:00 by narajaon          #+#    #+#             */
/*   Updated: 2017/10/18 12:10:47 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_bool			is_env_var(char *str, char *var)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (ft_strncmp(str, var, i) == 0)
		return (TRUE);
	return (FALSE);
}

t_bool			contains_esc_char(char *str)
{
	while (*str)
	{
		if (is_esc_char(str) >= 0)
			return (TRUE);
		str++;
	}
	return (FALSE);
}

char			**format_equal_args(char **arg, char *str, int i)
{
	char		*tmp_1;
	char		*tmp_2;

	arg = ft_memalloc(sizeof(char *) * 3);
	arg[0] = ft_strsub(str, 0, i);
	if (ft_strlen(&str[i + 1]) > 0)
		arg[1] = ft_strsub(&str[i + 1], 0, ft_strlen(&str[i + 1]));
	else
		arg[1] = ft_strdup("");
	arg[2] = 0;
	tmp_1 = arg[0];
	tmp_2 = arg[1];
	arg[0] = ft_strtrimc(arg[0], '"');
	arg[1] = ft_strtrimc(arg[1], '"');
	arg[2] = 0;
	free_str(&tmp_1);
	free_str(&tmp_2);
	return (arg);
}

t_bool			export_valid_arg(char *str, char ***arg)
{
	int			nb_equ;
	int			i;

	i = 0;
	nb_equ = 0;
	while (str[i] && str[i] != '=')
		i++;
	*arg = format_equal_args(*arg, str, i);
	if (contains_esc_char(**arg) == TRUE)
		return (FALSE);
	while (*str)
	{
		if (*str == '=')
			nb_equ++;
		if (nb_equ > 1 || ft_isprint(*str) == FALSE)
			return (FALSE);
		str++;
	}
	return (TRUE);
}

void			add_var_to_env(char **arg, t_list **env)
{
	char		*join;
	char		*str_tmp;

	join = ft_strjoin(arg[0], "=");
	str_tmp = join;
	if (arg[1] != NULL)
	{
		join = ft_strjoin(join, arg[1]);
		free_str(&str_tmp);
	}
	ft_lstpop(env, &is_env_var, join);
	ft_lstback(env, join, ft_strlen(join) + 1);
	free_str(&join);
}
