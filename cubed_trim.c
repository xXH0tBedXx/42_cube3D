/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 05:11:34 by tasian            #+#    #+#             */
/*   Updated: 2021/03/05 05:11:36 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

char	*color_trim(char *s1, const char *set)
{
	size_t		len_s;
	char		*trim_s;

	if (!s1 || !set)
		return (NULL);
	len_s = ft_strlen(s1);
	if (s1[len_s - 2] == ',')
		error_parser(7);
	if (s1[len_s - 1] == ',')
		len_s--;
	trim_s = ft_substr(s1, 0, len_s);
	free(s1);
	return (trim_s);
}

int		atoi_rgb(char *str)
{
	unsigned int	result;

	if (!str)
		return (0);
	result = 0;
	if (*str == '-')
		error_parser(7);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + (*str - '0');
		else
			return (-1);
		str++;
	}
	return (result);
}

char	**skips(char *line)
{
	char **text;

	if (ft_strchr(line + 1, ' '))
		text = ft_split(line, ' ');
	else
		text = ft_split(line + 1, ',');
	return (text);
}
