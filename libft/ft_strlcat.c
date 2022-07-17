/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:28:36 by tasian            #+#    #+#             */
/*   Updated: 2020/11/04 14:32:32 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*dst_cp;
	const char	*src_cp;
	size_t		counter;
	size_t		dst_len;

	counter = dstsize;
	src_cp = src;
	dst_cp = dst;
	while (counter-- != 0 && *dst_cp != '\0')
		dst_cp++;
	dst_len = dst_cp - dst;
	counter = dstsize - dst_len;
	if (counter == 0)
		return (dst_len + ft_strlen(src_cp));
	while (*src_cp != '\0')
	{
		if (counter != 1)
		{
			*dst_cp++ = *src_cp;
			counter--;
		}
		src_cp++;
	}
	*dst_cp = '\0';
	return (dst_len + (src_cp - src));
}
