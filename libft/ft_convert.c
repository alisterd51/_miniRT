/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:19:12 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/29 00:35:38 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check_sign(char *nbr, t_all *all)
{
	char	*new_nbr;
	
	if (all->flag->flag & SHOWSIGNFLAG)
	{
		new_nbr = ft_strjoin("+", nbr);
		free(nbr);
		return (new_nbr);
	}
	if (all->flag->flag & BLANKFLAG && *nbr != '-')
	{
		new_nbr = ft_strjoin(" ", nbr);
		free(nbr);
		return (new_nbr);
	}
	return (nbr);
}

char		*ft_printf_itoa(t_all *all, va_list ap)
{
	long long int	nb;

	if (all->flag->flag & LONGLONGFLAG)
		nb = va_arg(ap, long long);
	else if (all->flag->flag & LONGFLAG)
		nb = va_arg(ap, long);
	else if (all->flag->flag & HALFHALFFLAG)
		nb = (signed char)va_arg(ap, int);
	else if (all->flag->flag & HALFFLAG)
		nb = (short)va_arg(ap, int);
	else
		nb = va_arg(ap, int);
	return (check_sign(ft_itoa(nb), all));
}

char		*ft_printf_utoa(t_all *all, va_list ap)
{
	unsigned long long	nb;

	if (all->flag->flag & LONGLONGFLAG)
		nb = va_arg(ap, unsigned long long);
	else if (all->flag->flag & LONGFLAG)
		nb = va_arg(ap, unsigned long);
	else if (all->flag->flag & HALFHALFFLAG)
		nb = (unsigned char)va_arg(ap, unsigned int);
	else if (all->flag->flag & HALFFLAG)
		nb = (unsigned short)va_arg(ap, unsigned int);
	else
		nb = va_arg(ap, unsigned int);
	return (ft_utoa(nb));
}

char		*ft_printf_utoa_base(t_all *all, va_list ap, char *base)
{
	unsigned long long int	nb;

	if (all->flag->flag & LONGLONGFLAG)
		nb = va_arg(ap, unsigned long long);
	else if (all->flag->flag & LONGFLAG)
		nb = va_arg(ap, unsigned long);
	else if (all->flag->flag & HALFHALFFLAG)
		nb = (unsigned char)va_arg(ap, unsigned int);
	else if (all->flag->flag & HALFFLAG)
		nb = (unsigned short)va_arg(ap, unsigned int);
	else
		nb = va_arg(ap, unsigned int);
	return (ft_utoa_base(nb, base));
}
