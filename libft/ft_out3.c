/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:05:48 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/07 10:34:45 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_calculation_size_nbr(int *size_nbr, char *nbr, t_all *all)
{
	*size_nbr = ft_strlen(nbr);
	if (*nbr == '-')
	{
		(void)(*size_nbr)--;
		all->flag->width--;
	}
	if (*nbr == '0' && (all->flag->flag & POINTFLAG) && !all->flag->precision)
		*size_nbr = 0;
}

void	ft_calculation_nb_space1(int *size_nbr, int *nb_space1, t_all *all)
{
	if (all->flag->flag & LEADZEROFLAG)
		*nb_space1 = 0;
	else
		*nb_space1 = all->flag->width - *size_nbr -
			(all->flag->flag & ALTFLAG ? 2 : 0);
	if (all->flag->flag & POINTFLAG)
		*nb_space1 = all->flag->width -
			(all->flag->precision < *size_nbr ? *size_nbr :
			all->flag->precision) - (all->flag->flag & ALTFLAG ? 2 : 0);
}

void	ft_calculation_nb_space2(int *nb_space1, int *nb_space2, t_all *all)
{
	*nb_space2 = 0;
	if (all->flag->flag & LEFTFORMATFLAG)
	{
		*nb_space2 = *nb_space1;
		*nb_space1 = 0;
	}
}
