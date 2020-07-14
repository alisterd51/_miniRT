/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:30:19 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/07 10:33:09 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	i = -1;
	if (dst < src)
		while (++i < len)
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
	else if (src < dst)
		while (0 < len--)
			*((unsigned char *)dst + len) = *((unsigned char *)src + len);
	return (dst);
}
