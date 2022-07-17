/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:57:10 by tasian            #+#    #+#             */
/*   Updated: 2020/11/17 20:53:14 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *old;

	if (del && *lst)
	{
		while (*lst)
		{
			del((*lst)->content);
			old = *lst;
			*lst = old->next;
			free(old);
		}
		*lst = NULL;
	}
}
