/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 23:03:30 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/13 14:47:48 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned long long int n)
{
	char					*nb;
	unsigned long long int	nbtmp;
	int						size;
	char					sign;

	sign = 1;
	size = (sign > 0 ? 0 : 1) + (n == 0 ? 1 : 0);
	nbtmp = (unsigned long long int)n * sign;
	while (nbtmp > 0)
	{
		nbtmp /= 10;
		size++;
	}
	if (!(nb = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	nbtmp = (unsigned long long int)n * sign;
	nb[size] = '\0';
	while (--size >= 0)
	{
		nb[size] = nbtmp % 10 + '0';
		nbtmp /= 10;
	}
	if (sign < 0)
		nb[0] = '-';
	return (nb);
}
