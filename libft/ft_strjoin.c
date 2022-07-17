/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:36:32 by tasian            #+#    #+#             */
/*   Updated: 2020/11/09 18:42:56 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*str;
	int		counter_ebuchiy;

	if (s1 && !s2)
		return ((char *)s1);
	if (!s1 && s2)
		return ((char *)s2);
	if (s1 && s2)
	{
		len_s1 = (s1 ? ft_strlen(s1) : 0);
		len_s2 = (s2 ? ft_strlen(s2) : 0);
		if (!(str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
			return (NULL);
		str[len_s1 + len_s2] = '\0';
		counter_ebuchiy = -1;
		while (s1[++counter_ebuchiy])
			str[counter_ebuchiy] = s1[counter_ebuchiy];
		counter_ebuchiy = -1;
		while (s2[++counter_ebuchiy])
			str[len_s1++] = s2[counter_ebuchiy];
		return (str);
	}
	return (NULL);
}
