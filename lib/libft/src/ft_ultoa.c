/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 13:15:36 by narajaon          #+#    #+#             */
/*   Updated: 2017/11/24 03:03:24 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		base_len(unsigned long long n)
{
	if (n < 10)
		return (1);
	return (base_len(n / 10) + 1);
}

static char		*to_asci(char *str, unsigned long long n)
{
	if (n >= 10)
	{
		to_asci(str, n / 10);
		to_asci(str, n % 10);
	}
	if (n < 10)
	{
		while (*str)
			str++;
		*str = n + '0';
	}
	return (str);
}

int				ft_ultoa_str(unsigned long long n, char *str)
{
	int		ret;

	ret = base_len(n);
	to_asci(str, n);
	return (ret);
}
