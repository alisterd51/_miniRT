/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:11:35 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/07 10:45:06 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(unsigned long long int nb, char *base)
{
	size_t					base_len;
	unsigned long long int	nbtmp;
	int						dst_len;
	char					*dst;

	base_len = ft_strlen(base);
	dst_len = (nb == 0 ? 1 : 0);
	nbtmp = (unsigned long long int)nb;
	while (nbtmp > 0)
	{
		nbtmp /= base_len;
		dst_len++;
	}
	if (!(dst = malloc(sizeof(char) * (dst_len + 1))))
		return (NULL);
	nbtmp = (unsigned long long int)nb;
	dst[dst_len] = '\0';
	while (--dst_len >= 0)
	{
		dst[dst_len] = base[nbtmp % base_len];
		nbtmp /= base_len;
	}
	return (dst);
}
