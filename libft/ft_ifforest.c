/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifforest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:23:17 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/29 08:01:26 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_format_num1(t_all *all, char c, va_list ap)
{
	if (all->flag->flag & POINTFLAG)
	{
		all->flag->precision *= 10;
		all->flag->precision += c - '0';
	}
	else
	{
		if (c == '0' && all->flag->width == 0)
			all->flag->flag |= LEADZEROFLAG;
		all->flag->width *= 10;
		all->flag->width += c - '0';
	}
	return (ft_ifforest(all, ap));
}

static void	ft_format_num2(t_all *all, int num, va_list ap)
{
	if (all->flag->flag & POINTFLAG)
	{
		if (num < 0)
			all->flag->flag -= POINTFLAG;
		all->flag->precision = num;
	}
	else
	{
		if (num < 0)
		{
			all->flag->flag |= LEFTFORMATFLAG;
			num *= -1;
		}
		all->flag->width = num;
	}
	return (ft_ifforest(all, ap));
}

static int	ft_flagforest(t_all *all, char c)
{
	if (c == '.')
		all->flag->flag |= POINTFLAG;
	else if (c == '-')
		all->flag->flag |= LEFTFORMATFLAG;
	else if (c == '+')
		all->flag->flag |= SHOWSIGNFLAG;
	else if (c == ' ')
		all->flag->flag |= BLANKFLAG;
	else if (c == '#')
		all->flag->flag |= ALTFLAG;
	else if (c == 'l')
		all->flag->flag |= (all->flag->flag & LONGFLAG) ?
			LONGLONGFLAG : LONGFLAG;
	else if (c == 'h')
		all->flag->flag |= (all->flag->flag & HALFFLAG) ?
			HALFHALFFLAG : HALFFLAG;
	else if (c == 'p')
		all->flag->flag |= LONGFLAG | ALTFLAG;
	else if (c == 'X')
		all->flag->flag |= CAPSFLAG;
	else
		return (0);
	return (1);
}

static void	ft_ifforest_next(char c, int flag, t_all *all, va_list ap)
{
	if (flag)
		return (ft_ifforest(all, ap));
	ft_outputchar(all, '%');
	if (c != '\0')
	{
		ft_outputchar(all, c);
		return (ft_ifforest(all, ap));
	}
}

void		ft_ifforest(t_all *all, va_list ap)
{
	char	c;
	int		flag;

	c = *(all->cpy_format)++;
	flag = ft_flagforest(all, c);
	if (ft_isdigit(c))
		return (ft_format_num1(all, c, ap));
	else if (c == '*')
		return (ft_format_num2(all, va_arg(ap, int), ap));
	else if (c == '%')
		return (ft_outputchar(all, '%'));
	else if (c == 'c')
		return (ft_outputchar(all, va_arg(ap, unsigned int)));
	else if (c == 's')
		return (ft_outputstring(all, va_arg(ap, const char *)));
	else if (c == 'i' || c == 'd')
		return (ft_outputinteger(all, ap));
	else if (c == 'u')
		return (ft_outputunsigned(all, ap));
	else if (c == 'p' || c == 'X' || c == 'x')
		return (ft_outputhex(all, ap));
	else if (c == 'n')
		return (ft_outputwritten(all, va_arg(ap, int *)));
	else
		return (ft_ifforest_next(c, flag, all, ap));
}
