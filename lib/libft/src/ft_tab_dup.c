/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:08:56 by narajaon          #+#    #+#             */
/*   Updated: 2018/01/31 17:02:27 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char		**ft_tab_dup(char **tab)
{
	char	**dup;
	int		size;
	int		i;

	i = 0;
	size = ft_tab_size(tab);
	dup = ft_memalloc(sizeof(char *) * (size + 1));
	while (tab[i])
	{
		dup[i] = ft_strdup(tab[i]);
		i++;
	}
	dup[i] = 0;
	return (dup);
}
