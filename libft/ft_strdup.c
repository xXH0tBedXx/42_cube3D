/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:35:57 by tasian            #+#    #+#             */
/*   Updated: 2020/11/01 17:52:38 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;
	size_t	counter;

	counter = 0;
	len = 0;
	while (s1[len])
		len++;
	if (!(copy = malloc((size_t)len + 1)) || !(s1))
		return (NULL);
	while (counter < len)
	{
		copy[counter] = (char)s1[counter];
		counter++;
	}
	copy[counter] = '\0';
	return (copy);
}
