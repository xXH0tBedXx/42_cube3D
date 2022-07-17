/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:38:08 by tasian            #+#    #+#             */
/*   Updated: 2020/11/03 14:53:43 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*index;
	char	flag;

	flag = 0;
	c = (unsigned char)c;
	index = 0;
	if (c == '\0')
		return (ft_strchr(s, '\0'));
	while (*s)
	{
		if (*s == c)
		{
			index = (char *)s;
			flag = 1;
		}
		s++;
	}
	if (!flag)
		return ((char *)s);
	return (index);
}
