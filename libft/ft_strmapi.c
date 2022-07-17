/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:15:18 by tasian            #+#    #+#             */
/*   Updated: 2020/11/07 15:37:51 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*cp_s;
	unsigned int	counter;

	cp_s = NULL;
	counter = 0;
	if (!s)
		return (NULL);
	if (!(cp_s = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[counter] != '\0')
	{
		cp_s[counter] = f(counter, s[counter]);
		counter++;
	}
	cp_s[counter] = '\0';
	return (cp_s);
}
