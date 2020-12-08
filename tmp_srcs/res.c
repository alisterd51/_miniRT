/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 12:44:16 by anclarma          #+#    #+#             */
/*   Updated: 2020/12/07 17:20:22 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "exit_err.h"
#include "libft.h"
#include "read_line.h"

void	init_res(char *line, t_obj *obj)
{
	if (obj->res)
		return (exit_errcode(TO_MANY_RES_DECLARATION));
	obj->res = (t_res *)malloc(sizeof(t_res));
	if (!obj->res)
		return (exit_errcode(MALLOC_ERROR));
	while (ft_isspace(*line))
		line++;
	obj->res->x_size = read_line_to_int(&line);
	if (!ft_isspace(*line))
		return (exit_errcode(RES_ERROR_LINE));
	while (ft_isspace(*line))
		line++;
	obj->res->y_size = read_line_to_int(&line);
	if (*line)
		return (exit_errcode(RES_ERROR_LINE));
}

void	free_res(t_obj *obj)
{
	free(obj->res);
	obj->res = NULL;
}
