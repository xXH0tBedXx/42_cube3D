/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:38:03 by tasian            #+#    #+#             */
/*   Updated: 2020/11/14 01:57:04 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newlist;
	t_list *begin_list;

	if (!f || !lst || !del)
		return (NULL);
	if (!(begin_list = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	newlist = begin_list;
	lst = lst->next;
	while (lst)
	{
		if (!(begin_list = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&newlist, begin_list);
	}
	return (newlist);
}
