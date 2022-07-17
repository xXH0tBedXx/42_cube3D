/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:25:50 by tasian            #+#    #+#             */
/*   Updated: 2020/11/02 12:02:36 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*char_src;
	char			*char_dst;
	unsigned int	count;

	count = 0;
	char_src = (char *)src;
	char_dst = (char *)dst;
	if (dst == NULL && src == NULL)
		return (dst);
	while (count < n)
	{
		char_dst[count] = char_src[count];
		count++;
	}
	return (dst);
}
