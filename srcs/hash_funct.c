/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:52:13 by narajaon          #+#    #+#             */
/*   Updated: 2017/10/18 12:12:09 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int				is_esc_char(char *str)
{
	int		i;

	i = 0;
	while (i < SCHAR_NB)
	{
		if (ft_strncmp(g_spec_char[i].sequ, str, 2) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char			*replace_spec_char(char *user_in, int size)
{
	char		*formated;
	int			esc_index;
	int			i;

	i = 0;
	formated = ft_memalloc(size);
	while (*user_in != '\0')
	{
		if ((esc_index = is_esc_char(user_in)) >= 0)
		{
			formated[i] = g_spec_char[esc_index].asc;
			user_in++;
			if (*user_in == '\0')
				break ;
		}
		else
			formated[i] = *user_in;
		user_in++;
		i++;
	}
	formated[i] = '\0';
	return (formated);
}

void			format_input(char **str)
{
	int		in_size;
	char	*formated;

	in_size = ft_strlen(*str) + 1;
	formated = replace_spec_char(*str, in_size);
	free_str(str);
	*str = formated;
}
