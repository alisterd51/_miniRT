/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:08:14 by antoine           #+#    #+#             */
/*   Updated: 2020/11/22 17:39:05 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "libft.h"
#include "exit_err.h"
#include "to_char.h"

/*
** DESCRIPTION
*/
int			read_line_to_int(char **line)
{
	int		ret;

	while (ft_isspace(**line))
		(*line)++;
	ret = ft_atoi(*line);
	if (**line == '+' || **line == '-')
		(*line)++;
	while (ft_isdigit(**line))
		(*line)++;
	return (ret);
}

double		read_line_to_double(char **line)
{
	double	ret;

	while (ft_isspace(**line))
		(*line)++;
	ret = ft_atof(*line);	
	if (**line == '+' || **line == '-')
		(*line)++;
	while (ft_isdigit(**line))
		(*line)++;
	if (**line != '.')
		return (ret);
	(*line)++;
	while (ft_isdigit(**line))
		(*line)++;
	return (ret);
}

t_color		read_line_to_color(char **line)
{
	t_color	ret;
	int		tmp_value;

	ret.depth = 0x00;
	tmp_value = read_line_to_int(line);
	if (is_not_char(tmp_value) || **line != ',')
		ret.depth = 0xFF;
	ret.r = int_to_char(tmp_value);
	if (**line == ',')
		(*line)++;
	tmp_value = read_line_to_int(line);
	if (is_not_char(tmp_value) || **line != ',')
		ret.depth = 0xFF;
	ret.g = int_to_char(tmp_value);
	if (**line == ',')
		(*line)++;
	tmp_value = read_line_to_int(line);
	if (is_not_char(tmp_value) || (**line && ft_isspace(**line)))
		ret.depth = 0xFF;
	ret.b = int_to_char(tmp_value);
	return (ret);
}
