/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 09:53:17 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/07 10:35:16 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_remove_flag(t_flag *flag)
{
	flag->flag = 0x00000000;
	flag->width = 0;
	flag->precision = 0;
}

static t_all	*ft_init_all(const char *format)
{
	t_all	*all;

	if (!(all = malloc(sizeof(t_all))))
		return (NULL);
	if (!(all->out = malloc(sizeof(t_out))))
		return (NULL);
	all->out->current_size = 0;
	all->out->final_size = 0;
	if (!(all->flag = malloc(sizeof(t_flag))))
	{
		free(all->out);
		free(all);
		return (NULL);
	}
	all->cpy_format = ft_strdup(format);
	all->cpy_format_init = all->cpy_format;
	return (all);
}

static void		ft_free_all(t_all *all)
{
	free(all->flag);
	free(all->out);
	free(all->cpy_format_init);
	free(all);
}

static int		ft_parseprintf(const char *format, va_list ap)
{
	int		size;
	t_all	*all;

	all = ft_init_all(format);
	while (*(all->cpy_format))
	{
		ft_remove_flag(all->flag);
		if (*(all->cpy_format)++ == '%')
			ft_ifforest(all, ap);
		else
			ft_outputchar(all, *(all->cpy_format - 1));
	}
	size = ft_cleanbufferprintf(all->out);
	ft_free_all(all);
	return (size);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_parseprintf(format, ap);
	va_end(ap);
	return (ret);
}
