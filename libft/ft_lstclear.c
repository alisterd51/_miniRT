/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:30:19 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/07 10:27:51 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*ptr2;

	if (*lst == NULL)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		ptr2 = ptr->next;
		del(ptr->content);
		free(ptr);
		ptr = ptr2;
	}
	*lst = NULL;
}
