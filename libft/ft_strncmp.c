/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:20:14 by tasian            #+#    #+#             */
/*   Updated: 2020/11/06 03:30:55 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
		if (!n || !(s1 || s2))
			return (0);
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
