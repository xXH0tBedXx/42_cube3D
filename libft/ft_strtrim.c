/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 06:42:12 by tasian            #+#    #+#             */
/*   Updated: 2020/11/12 00:34:22 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t		len_s;
	char		*trim_s;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len_s = ft_strlen(s1);
	while (len_s && ft_strchr(set, s1[len_s]))
		len_s--;
	trim_s = ft_substr((char*)s1, 0, len_s + 1);
	return (trim_s);
}
