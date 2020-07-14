/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:12:30 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/07 10:29:11 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new_lst)
{
	t_list	*ptr;

	if (!alst)
		return ;
	ptr = *alst;
	if (*alst == NULL)
		*alst = new_lst;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new_lst;
	}
}
