/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:36:55 by antoine           #+#    #+#             */
/*   Updated: 2020/11/29 23:31:11 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (!ft_isspace(*line))
		return (exit_errcode(AMB_LIGHT_ERROR_LINE));
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
