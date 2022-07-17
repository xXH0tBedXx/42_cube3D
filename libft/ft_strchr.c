/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:07:07 by tasian            #+#    #+#             */
/*   Updated: 2020/10/31 17:48:03 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		count;
	char	*temp;

	temp = (char *)s;
	count = 0;
	while (s[count] != (char)c && s[count])
	{
		temp++;
		count++;
	}
	if (*temp != (char)c)
		return (NULL);
	return (temp);
}
