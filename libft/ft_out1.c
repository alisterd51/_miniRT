/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:22:30 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/29 07:41:19 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_outputchar(t_all *all, int c)
{
	if (!(all->flag->flag & POINTFLAG))
		all->flag->precision = INT_MAX;
	if (!(all->flag->flag & LEFTFORMATFLAG))
		ft_padding(all, all->flag->width - 1,
				(all->flag->flag & LEADZEROFLAG) ? '0' : ' ');
	ft_checkbufferprintf(all->out);
	(all->out->str)[all->out->current_size++] = c;
	if (all->flag->flag & LEFTFORMATFLAG)
		ft_padding(all, all->flag->width - 1, ' ');
}

void	ft_outputstring(t_all *all, const char *str)
{
	int size_buffer;
	int	size_str;
	int	cpy_size_str;

	if (!str)
		str = "(null)";
	if (!(all->flag->flag & POINTFLAG))
		all->flag->precision = INT_MAX;
	size_buffer = ft_checkbufferprintf(all->out);
	all->flag->precision = ft_strnlen(str, all->flag->precision);
	size_str = all->flag->flag & POINTFLAG ?
		all->flag->precision : (int)ft_strlen(str);
	cpy_size_str = size_str;
	if (!(all->flag->flag & LEFTFORMATFLAG))
		ft_padding(all, all->flag->width - size_str, ' ');
	while (size_str > 0 && all->flag->precision > 0)
	{
		while (size_buffer-- > 0 && size_str-- > 0)
			(all->out->str)[all->out->current_size++] = *str++;
		size_buffer = ft_checkbufferprintf(all->out);
		all->flag->precision++;
	}
	if (all->flag->flag & LEFTFORMATFLAG)
		ft_padding(all, all->flag->width - cpy_size_str, ' ');
}

void	ft_outputinteger(t_all *all, va_list ap)
{
	char	*nbr;

	nbr = ft_printf_itoa(all, ap);
	ft_outputnumber(all, nbr);
	free(nbr);
}

void	ft_outputunsigned(t_all *all, va_list ap)
{
	char	*nbr;

	nbr = ft_printf_utoa(all, ap);
	ft_outputnumber(all, nbr);
	free(nbr);
}

void	ft_outputhex(t_all *all, va_list ap)
{
	char	*nbr;
	char	*base;

	if (all->flag->flag & ALTFLAG)
	{
		ft_padding(all, 1, '0');
		ft_padding(all, 1, all->flag->flag & CAPSFLAG ? 'X' : 'x');
	}
	base = all->flag->flag & CAPSFLAG ? "0123456789ABCDEF" : "0123456789abcdef";
	nbr = ft_printf_utoa_base(all, ap, base);
	ft_outputnumber(all, nbr);
	free(nbr);
}
