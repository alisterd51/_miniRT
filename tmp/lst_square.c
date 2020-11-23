/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:32:16 by antoine           #+#    #+#             */
/*   Updated: 2020/11/23 17:30:00 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "exit_err.h"
#include "read_line.h"
#include "libft.h"

void	add_end_lst_square(t_square *new_square, t_obj *obj)
{
	t_square	*tmp_square;

	if (!obj->lst_square)
		obj->lst_square = new_square;
	else
	{
		tmp_square = obj->lst_square;
		while (tmp_square->next)
			tmp_square = tmp_square->next;
		tmp_square->next = new_square;
	}
}

void	init_lst_square(char *line, t_obj *obj)
{
	t_square	*square;

	if (!(square = (t_square *)malloc(sizeof(t_square))))
		return (exit_errcode(MALLOC_ERROR));
	square->coord = read_line_to_vector(&line);
	square->normal = read_line_to_vector(&line);
	square->side = read_line_to_double(&line);
	square->color = read_line_to_color(&line);
	square->next = NULL;
	if (*line || square->color.depth)
		return (exit_errcode(SQUARE_ERROR_LINE));
	add_end_lst_square(square, obj);
}

void	free_lst_square(t_obj *obj)
{
	t_square	*square;
	t_square	*next_square;

	square = obj->lst_square;
	while (square)
	{
		next_square = square->next;
		free(square);
		square = next_square;
	}
	obj->lst_square = NULL;
}
