/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:43:44 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/07 10:26:56 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long int nb, char *base)
{
	size_t					base_len;
	unsigned long long int	nbtmp;
	int						dst_len;
	int						sign;
	char					*dst;

	base_len = ft_strlen(base);
	sign = nb < 0 ? -1 : 1;
	dst_len = (sign > 0 ? 0 : 1) + (nb == 0 ? 1 : 0);
	nbtmp = (unsigned long long int)nb * sign;
	while (nbtmp > 0)
	{
		nbtmp /= base_len;
		dst_len++;
	}
	if (!(dst = calloc(sizeof(char), dst_len + 1)))
		return (NULL);
	nbtmp = (unsigned long long int)nb * sign;
	while (--dst_len >= 0)
	{
		dst[dst_len] = base[nbtmp % base_len];
		nbtmp /= base_len;
	}
	(sign < 0) ? *dst = '-' : (void)dst;
	return (dst);
}
