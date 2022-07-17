/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:07:42 by tasian            #+#    #+#             */
/*   Updated: 2020/11/01 15:31:51 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*char_s;

	char_s = (unsigned char *)s;
	while (n--)
	{
		if (*char_s == (unsigned char)c)
			return (char_s);
		char_s++;
	}
	return (NULL);
}
