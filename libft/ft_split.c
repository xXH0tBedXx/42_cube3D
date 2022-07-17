/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:43:35 by tasian            #+#    #+#             */
/*   Updated: 2020/11/10 00:30:02 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**ft_malloc_error(char **tab)
{
	unsigned int	index;

	index = 0;
	while (tab[index])
	{
		free(tab[index]);
		index++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_srch_count_str(const char *s, char c)
{
	unsigned int	index;
	unsigned int	count_str;

	index = 0;
	count_str = 0;
	if (!s[index])
		return (0);
	while (s[index] && s[index] == c)
		index++;
	while (s[index])
	{
		if (s[index] == c)
		{
			count_str++;
			while (s[index] && s[index] == c)
				index++;
			continue;
		}
		index++;
	}
	if (s[index - 1] != c)
		count_str++;
	return (count_str);
}

static void			ft_next_strlen(char **next_str, unsigned int *next_str_len,
					char c)
{
	unsigned int index;

	*next_str += *next_str_len;
	*next_str_len = 0;
	index = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[index])
	{
		if ((*next_str)[index] == c)
			return ;
		(*next_str_len)++;
		index++;
	}
}

char				**ft_split(const char *s, char c)
{
	char			**tab;
	char			*next_str;
	unsigned int	next_str_len;
	unsigned int	count_str;
	unsigned int	index;

	if (!s)
		return (NULL);
	count_str = ft_srch_count_str(s, c);
	if (!(tab = malloc(sizeof(char *) * (count_str + 1))))
		return (NULL);
	index = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (index < count_str)
	{
		ft_next_strlen(&next_str, &next_str_len, c);
		if (!(tab[index] = malloc(sizeof(char) * (next_str_len + 1))))
			return (ft_malloc_error(tab));
		ft_strlcpy(tab[index], next_str, next_str_len + 1);
		index++;
	}
	tab[index] = NULL;
	return (tab);
}
