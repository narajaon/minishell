/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:09:24 by narajaon          #+#    #+#             */
/*   Updated: 2017/10/19 16:35:23 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstpop(t_list **list, t_bool (*cmp)(), void *to_cmp)
{
	t_list		*tmp;
	t_list		*to_free;

	tmp = *list;
	if (tmp == NULL)
		return ;
	if (cmp(tmp->content, to_cmp) == TRUE)
	{
		to_free = *list;
		*list = tmp->next;
		free(to_free->content);
		free(to_free);
		return ;
	}
	while (tmp && tmp->next)
	{
		if (cmp(tmp->next->content, to_cmp) == TRUE)
		{
			to_free = tmp->next;
			tmp->next = tmp->next->next;
			free(to_free->content);
			free(to_free);
		}
		tmp = tmp->next;
	}
}
