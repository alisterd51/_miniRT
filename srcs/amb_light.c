/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:36:55 by antoine           #+#    #+#             */
/*   Updated: 2021/02/22 09:30:37 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "struct.h"
#include "libft.h"
#include "exit_err.h"
#include "read_line.h"

/*
** DESCRIPTION
**	Cette fonction lit une ligne normalise et parametre la lumiere ambiante
**	de la scene.
** ERRORS
**	En cas de parametre incorecte, la fonction exit_errcode est appelle avec
**	un code approprie.
*/

void	init_amb_light(char *line, t_obj *obj)
{
	if (obj->amb_light)
		return (exit_errcode(TO_MANY_AMB_LIGHT_DECLARATION));
	obj->amb_light = (t_amb_light *)malloc(sizeof(t_amb_light));
	if (!obj->amb_light)
		return (exit_errcode(MALLOC_ERROR));
	while (ft_isspace(*line))
		line++;
	obj->amb_light->ratio = read_line_to_double(&line);
	if (obj->amb_light->ratio == DBL_MIN || !ft_isspace(*line))
		return (exit_errcode(AMB_LIGHT_ERROR_LINE));
	if (obj->amb_light->ratio < 0.0 || 1.0 < obj->amb_light->ratio)
		return (exit_errcode(AMB_LIGHT_RANGE_ERROR));
	while (ft_isspace(*line))
		line++;
	obj->amb_light->color = read_line_to_color(&line);
	if (*line || obj->amb_light->color.depth)
		return (exit_errcode(AMB_LIGHT_ERROR_LINE));
}

/*
** DESCRIPTION
**	la fonction libere la mémoire de la lumiere ambiante de la scene.
*/

void	free_amb_light(t_obj *obj)
{
	free(obj->amb_light);
	obj->amb_light = NULL;
}
