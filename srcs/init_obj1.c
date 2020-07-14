/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 10:38:48 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/13 10:43:51 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "libft.h"

int			read_int(char **line)
{
	int	ret;

	while (ft_isspace(**line))
		(*line)++;
	ret = ft_atoi(*line);
	if (**line == '+' || **line == '-')
		(*line)++;
	while (ft_isdigit(**line))
		(*line)++;
	if (**line == ',')
		(*line)++;
	return (ret);
}

double		read_float(char **line)
{
	double	ret;

	while (ft_isspace(**line))
		(*line)++;
	ret = ft_atof(*line);
	if (**line == '+' || **line == '-')
		(*line)++;
	while (ft_isdigit(**line))
		(*line)++;
	if (**line == '.')
		(*line)++;
	while (ft_isdigit(**line))
		(*line)++;
	if (**line == ',')
		(*line)++;
	return (ret);
}

t_vector	read_vec(char **line)
{
	t_vector	vec;

	vec.x = read_float(line);
	vec.y = read_float(line);
	vec.z = read_float(line);
	return (vec);
}

int			read_color(char **line)
{
	int			ret;

	ret = read_int(line) * 0x00010000;
	ret += read_int(line) * 0x00000100;
	ret += read_int(line);
	return (ret);
}

int			read_option(char **line)
{
	int	ret;

	while (ft_isspace(**line))
		(*line)++;
	if (**line == 'm')
		ret = 1;
	else
		ret = 0;
	return (ret);
}

int         read_option2(char **line)
{
    int ret;

    while (ft_isspace(**line))
        (*line)++;
    if (**line == 't')
        ret = 1;
    else
        ret = 0;
    return (ret);
}
