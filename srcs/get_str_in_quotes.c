/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_in_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:52:08 by narajaon          #+#    #+#             */
/*   Updated: 2017/10/18 11:52:08 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_bool		is_esc_c(char *str, char *esc)
{
	if (ft_strncmp(str, esc, 2) == 0)
		return (TRUE);
	return (FALSE);
}

char		*get_str_in_quotes(char *str, int *pos)
{
	char	*content;
	int		i;

	i = 0;
	if (*str != '"')
	{
		while (str[i] && (ft_isspace(str[i]) == FALSE && str[i] != '"'))
			i++;
		*pos = i;
		return (ft_strndup(str, i));
	}
	str++;
	i = 0;
	while (str[i])
	{
		if (is_esc_c(&str[i], "\\\"") == TRUE)
			i++;
		else if (str[i] == '"')
			break ;
		i++;
	}
	content = ft_strsub(str, 0, i);
	*pos = i + 2;
	return (content);
}
