/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:26:03 by tasian            #+#    #+#             */
/*   Updated: 2020/11/11 21:47:48 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_intlen(int number)
{
	int	len;

	len = 0;
	if (number == -2147483648)
		return (10);
	if (number < 0)
	{
		number = number * -1;
		len++;
	}
	while (number > 0)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	cp_n;
	int				len;

	cp_n = (n == -2147483648 ? 2147483648 : n);
	cp_n = (n < 0 ? -n : n);
	len = ft_intlen(cp_n);
	if (n == 0)
		return (ft_strdup("0"));
	if (!(str = (char*)malloc(sizeof(char) * (len + 1 + (n <= 0 ? 1 : 0)))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		len++;
	}
	str[len--] = '\0';
	while (cp_n >= 10)
	{
		str[len] = '0' + (cp_n % 10);
		cp_n = cp_n / 10;
		len--;
	}
	str[len] = '0' + (cp_n % 10);
	return (str);
}
