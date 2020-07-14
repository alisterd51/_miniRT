/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:18:55 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/07 10:21:28 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	size_t			len;
	unsigned char	*dst;

	len = count * size;
	if (!(dst = malloc(len)))
		return (NULL);
	i = -1;
	while (++i < len)
		dst[i] = 0;
	return ((void *)dst);
}
