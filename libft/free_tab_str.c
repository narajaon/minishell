/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:11:38 by narajaon          #+#    #+#             */
/*   Updated: 2017/10/18 11:11:49 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		free_tab_str(char ***tab)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = *tab;
	if (tmp == NULL)
		return ;
	while (tmp[i])
		free_str(&tmp[i++]);
	free(*tab);
	*tab = NULL;
}
