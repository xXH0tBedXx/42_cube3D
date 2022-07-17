/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:36:44 by tasian            #+#    #+#             */
/*   Updated: 2020/11/09 17:44:25 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*char_dst;
	unsigned char	*char_src;
	size_t			count;

	count = 0;
	char_dst = (unsigned char *)dst;
	char_src = (unsigned char *)src;
	while (count < n)
	{
		if (char_src[count] == (unsigned char)c)
		{
			char_dst[count] = char_src[count];
			return (dst + count + 1);
		}
		char_dst[count] = char_src[count];
		count++;
	}
	return (NULL);
}
