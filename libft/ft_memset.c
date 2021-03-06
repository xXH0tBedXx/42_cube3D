/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:07:29 by tasian            #+#    #+#             */
/*   Updated: 2020/10/31 18:15:29 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*x;
	size_t	z;

	x = (char *)b;
	z = 0;
	while (z < len)
	{
		x[z] = c;
		z++;
	}
	return (b);
}
