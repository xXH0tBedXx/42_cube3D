/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 01:37:59 by tasian            #+#    #+#             */
/*   Updated: 2020/11/17 18:50:03 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	counter;
	unsigned int	len_s;
	char			*sub_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < start)
	{
		if (!(sub_s = malloc(sizeof(char) * 1)))
			return (NULL);
		sub_s[0] = '\0';
		return (sub_s);
	}
	if (!(sub_s = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	counter = 0;
	while (counter < len)
	{
		sub_s[counter] = s[start + counter];
		counter++;
	}
	sub_s[counter] = '\0';
	return (sub_s);
}
