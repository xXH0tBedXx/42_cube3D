/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:13:11 by tasian            #+#    #+#             */
/*   Updated: 2020/11/13 16:23:01 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int counter;

	counter = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}
