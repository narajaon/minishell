/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:52:05 by narajaon          #+#    #+#             */
/*   Updated: 2018/01/31 15:54:46 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_list			*ft_tab_to_list(char **str)
{
	t_list		*env_list;

	env_list = NULL;
	while (*str)
	{
		ft_lstback(&env_list, *str, ft_strlen(*str) + 1);
		str++;
	}
	return (env_list);
}
