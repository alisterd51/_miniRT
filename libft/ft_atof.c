/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 14:42:38 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/25 14:42:38 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double ft_atof(const char *str)
{
	double	nb;
	double	exp;
	int		sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	nb = 0.0;
	while ('0' <= *str && *str <= '9')
		nb = nb * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	exp = 1.0;
	while ('0' <= *str && *str <= '9')
	{
		exp /= 10;
		nb += (*str++ - '0') * exp;
	}
	return (nb * sign);
}
