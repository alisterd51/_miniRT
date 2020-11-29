/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:17:04 by antoine           #+#    #+#             */
/*   Updated: 2020/11/27 17:57:09 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "struct.h"
#include "vector.h"
#include "exit_err.h"
#include "read_line.h"
#include "lst_obj.h"
#include "rot_vector.h"

/*
** ne fonctionne pas
*/
void	test(t_square base, t_obj *obj)
{
	t_square	*square;
	t_vector	rot[6];
	int			i;

	rot[0] = init_vector(M_PI / 2.0, 0.0, 0.0);
	rot[1] = init_vector(M_PI / -2.0, 0.0, 0.0);
	rot[2] = init_vector(0.0, M_PI / 2.0, 0.0);
	rot[3] = init_vector(0.0, M_PI / -2.0, 0.0);
	rot[4] = init_vector(0.0, 0.0, M_PI / 2.0);
	rot[5] = init_vector(0.0, 0.0, M_PI / -2.0);
	i = -1;
	while (++i < 6)
	{
		if (!(square = (t_square *)malloc(sizeof(t_square))))
			return (exit_errcode(MALLOC_ERROR));
		square->normal = rot_vector(rot[i], base.normal);
		square->coord = add_vector(base.coord, mult_vector(base.side / 2.0, square->normal));
		square->side = base.side;
		square->color = base.color;
		square->next = NULL;
		add_end_lst_square(square, obj);
	}
}

void	init_lst_cube(char *line, t_obj *obj)
{
	t_square	square0;

	square0.coord = read_line_to_vector(&line);
	square0.normal = read_line_to_vector(&line);
	square0.side = read_line_to_double(&line);
	square0.color = read_line_to_color(&line);
	square0.next = NULL;
	if (*line || square0.color.depth)
		return (exit_errcode(CUBE_ERROR_LINE));
	test(square0, obj);
}
