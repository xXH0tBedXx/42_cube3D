/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:09:26 by tasian            #+#    #+#             */
/*   Updated: 2020/11/11 19:08:43 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	result;
	char		*tmp;

	if (!str)
		return (0);
	tmp = (char *)str;
	while (*tmp)
	{
		if (!(ft_isdigit(*tmp)))
			return (0);
		tmp++;
	}
	result = 0;
	if (str[0] <= '0' && str[0] >= '9')
		return (0);
	while (*str != '\0')
	{
		result = (result * 10 + (*str - '0'));
		if (result > 99999)
			return (99999);
		str++;
	}
	return ((int)result);
}
