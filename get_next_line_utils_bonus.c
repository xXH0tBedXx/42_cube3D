/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:29:18 by tasian            #+#    #+#             */
/*   Updated: 2020/11/28 19:09:01 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int			checker_n(char *str)
{
	int index;

	index = 0;
	if (!str)
		return (1);
	while (str[index])
	{
		if (str[index] == '\n')
			return (0);
		index++;
	}
	return (1);
}

size_t		ft_strlen(const char *line)
{
	int index;

	index = 0;
	if (!line)
		return (0);
	while (line[index] != '\0')
		index++;
	return (index);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	general_len;
	char	*new_string;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	general_len = s1_len + s2_len + 1;
	new_string = malloc(sizeof(char) * general_len);
	if (!new_string)
		return (0);
	ft_memmove(new_string, s1, s1_len);
	ft_memmove(new_string + s1_len, s2, s2_len);
	new_string[general_len - 1] = '\0';
	return (new_string);
}
