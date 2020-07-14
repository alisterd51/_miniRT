/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:45:22 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/07 10:31:04 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*dst;
	int		error;

	if (!lst)
		return (NULL);
	error = 0;
	if (!(newlst = ft_lstnew(f(lst->content))))
		error = 1;
	dst = newlst;
	lst = lst->next;
	while (lst && !error)
	{
		if (!(newlst->next = ft_lstnew(f(lst->content))))
			error = 1;
		newlst = newlst->next;
		lst = lst->next;
	}
	if (!error)
		return (dst);
	ft_lstclear(&dst, del);
	return (NULL);
}
