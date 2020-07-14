/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 01:32:01 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/07 10:34:59 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_padding(t_all *all, int size, char c)
{
	while (size-- > 0)
	{
		ft_checkbufferprintf(all->out);
		(all->out->str)[all->out->current_size++] = c;
	}
}
