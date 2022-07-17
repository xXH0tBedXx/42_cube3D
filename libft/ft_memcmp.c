/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:55:43 by tasian            #+#    #+#             */
/*   Updated: 2020/11/02 12:02:56 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *char_s1;
	unsigned char *char_s2;

	char_s1 = (unsigned char *)s1;
	char_s2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*char_s1 != *char_s2)
			return (*char_s1 - *char_s2);
		n--;
		char_s1++;
		char_s2++;
	}
	return (0);
}
