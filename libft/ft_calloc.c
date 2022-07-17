/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:04:56 by tasian            #+#    #+#             */
/*   Updated: 2020/11/01 20:32:29 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	z;
	void	*str;
	char	*char_str;

	z = 0;
	str = malloc(count * size);
	char_str = str;
	if (str == 0)
		return (str);
	while (z < (count * size))
	{
		char_str[z] = '\0';
		z++;
	}
	return (str);
}
