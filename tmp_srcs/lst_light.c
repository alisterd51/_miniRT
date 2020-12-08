/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:41:33 by antoine           #+#    #+#             */
/*   Updated: 2020/12/08 16:11:05 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "exit_err.h"
#include "read_line.h"
#include "libft.h"

void	init_lst_light(char *line, t_obj *obj)
{
	t_light	*light;
	t_light	*tmp_light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		return (exit_errcode(MALLOC_ERROR));
	light->coord = read_line_to_vector(&line);
	light->ratio = read_line_to_double(&line);
	light->color = read_line_to_color(&line);
	light->next = NULL;
	if (*line || light->color.depth)
		return (exit_errcode(LIGHT_ERROR_LINE));
	if (!obj->lst_light)
		obj->lst_light = light;
	else
	{
		tmp_light = obj->lst_light;
		while (tmp_light->next)
			tmp_light = tmp_light->next;
		tmp_light->next = light;
	}
}

void	free_lst_light(t_obj *obj)
{
	t_light	*light;
	t_light	*next_light;

	light = obj->lst_light;
	while (light)
	{
		next_light = light->next;
		free(light);
		light = next_light;
	}
	obj->lst_light = NULL;
}
