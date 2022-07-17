/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:05:15 by tasian            #+#    #+#             */
/*   Updated: 2020/11/16 01:33:23 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int		index;
	unsigned int		index2;

	if (!*needle)
		return ((char *)haystack);
	index = 0;
	while (haystack[index] && index < len)
	{
		index2 = 0;
		if (haystack[index] == needle[index2])
		{
			while (index + index2 < len &&
					haystack[index + index2] == needle[index2])
			{
				index2++;
				if (!needle[index2])
					return ((char *)&haystack[index]);
			}
		}
		index++;
	}
	return (0);
}
