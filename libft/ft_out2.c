/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 22:36:37 by anclarma          #+#    #+#             */
/*   Updated: 2021/03/08 13:00:52 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_outputwritten(t_all *all, int *ptr)
{
	*ptr = all->out->current_size;
}

void	ft_outputnumber(t_all *all, char *nbr)
{
	int	size_nbr;
	int	nb_space1;
	int	nb_space2;
	int	nb_zero;

	ft_calculation_size_nbr(&size_nbr, nbr, all);
	ft_calculation_nb_space1(&size_nbr, &nb_space1, all);
	ft_calculation_nb_space2(&nb_space1, &nb_space2, all);
	nb_zero = all->flag->width - nb_space1 - nb_space2 - size_nbr -
		(all->flag->flag & ALTFLAG ? 2 : 0);
	if (all->flag->flag & POINTFLAG)
		nb_zero = all->flag->precision - size_nbr;
	ft_padding(all, nb_space1, ' ');
	if (*nbr == '-')
		ft_padding(all, 1, *nbr++);
	ft_padding(all, nb_zero, '0');
	while (size_nbr && *nbr)
		ft_padding(all, 1, *nbr++);
	ft_padding(all, nb_space2, ' ');
}

int		ft_checkbufferprintf(t_out *out)
{
	int		diff;
	ssize_t	ret;

	diff = PRINTF_BUFFER - out->current_size;
	if (diff == 0)
	{
		ret = write(1, out->str, PRINTF_BUFFER);
		(void)ret;
		out->final_size += PRINTF_BUFFER;
		out->current_size = 0;
		return (PRINTF_BUFFER);
	}
	return (diff);
}

int		ft_cleanbufferprintf(t_out *out)
{
	ssize_t	ret;

	out->final_size += out->current_size;
	ret = write(1, out->str, out->current_size);
	out->current_size = 0;
	(void)ret;
	return (out->final_size);
}
