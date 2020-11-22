/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:36:55 by antoine           #+#    #+#             */
/*   Updated: 2020/11/22 15:01:57 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "libft.h"
#include "exit_err.h"
#include "read_line.h"

/*
**
*/
void	init_amb_light(char *line, t_obj *obj)
{
	if (obj->amb_light)
		return (exit_errcode(TO_MANY_AMB_LIGHT_DECLARATION));
	if (!(obj->amb_light = (t_amb_light *)malloc(sizeof(t_amb_light))))
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
**
*/
void	free_amb_light(t_obj *obj)
{
	free(obj->amb_light);
	obj->amb_light = NULL;
}
