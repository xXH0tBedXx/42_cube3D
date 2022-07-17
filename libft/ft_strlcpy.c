/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:48:21 by tasian            #+#    #+#             */
/*   Updated: 2020/11/06 21:04:11 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t counter;

	counter = 0;
	if (dst == NULL && src == NULL)
		return (0);
	if (dstsize > 0)
	{
		while (*(src + counter) != '\0' && counter != (dstsize - 1))
		{
			*(dst + counter) = *(src + counter);
			counter++;
		}
		*(dst + counter) = '\0';
	}
	while (*(src + counter) != '\0')
		counter++;
	return (counter);
}
