/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:08:14 by antoine           #+#    #+#             */
/*   Updated: 2021/03/21 16:11:50 by pompier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "struct.h"
#include "libft.h"
#include "exit_err.h"
#include "to_char.h"
#include "secure_atoi.h"

/*
** DESCRIPTION
*/

int			read_line_to_int(char **line)
{
	int		ret;

	while (ft_isspace(**line))
		(*line)++;
	if (!secure_atoi(*line))
		return (-1);
	ret = ft_atoi(*line);
	if (**line == '+' || **line == '-')
		(*line)++;
	if (!ft_isdigit(**line))
		return (-1);
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
	if (!ft_isdigit(**line))
		return (DBL_MIN);
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
	if (is_not_char(tmp_value) || (**line && !ft_isspace(**line)))
		ret.depth = 0xFF;
	ret.b = int_to_char(tmp_value);
	return (ret);
}

t_vector	read_line_to_vector(char **line)
{
	t_vector	ret;

	ret.x = read_line_to_double(line);
	if (**line == ',')
		(*line)++;
	ret.y = read_line_to_double(line);
	if (**line == ',')
		(*line)++;
	ret.z = read_line_to_double(line);
	return (ret);
}

char		*read_line_to_string(char **line)
{
	char	*ret;

	while (ft_isspace(**line))
		(*line)++;
	ret = ft_strdup(*line);
	return (ret);
}
