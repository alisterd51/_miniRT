/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:09:33 by anclarma          #+#    #+#             */
/*   Updated: 2020/08/24 12:38:59 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_obj.h"
#include "struct.h"
#include "vector.h"
#include <stdlib.h>

t_square	*creat_square(t_data data)
{
	t_square    *new_square;

	if (!(new_square = malloc(sizeof(t_square))))
		return (NULL);
	new_square->id = data.id;
	new_square->c = data.coord1;
	new_square->o = data.normal;
	new_square->height = data.size1;
	new_square->color = data.color;
	new_square->next = NULL;
	return (new_square);
}

int	add_newsquaretolst(t_square **lst_square, t_square *new_square)
{
	t_square	*ptr_tmp;

	if (new_square == NULL)
		return (1);
	if (*lst_square == NULL)
		*lst_square = new_square;
	else
	{
		new_square->id++;
        ptr_tmp = *lst_square;
        while (ptr_tmp->next != NULL)
        {
            new_square->id++;
            ptr_tmp = ptr_tmp->next;
        }
        ptr_tmp->next = new_square;
	}
	return (0);
}

int	init_cube(char *line, t_obj *obj)
{
	const t_vector	dir[6] = {init_vector(0,0,1), init_vector(0,0,-1),
		init_vector(0,1,0), init_vector(0,-1,0),
		init_vector(1,0,0), init_vector(-1,0,0)};
	t_data			data;
	t_data			param;
	int				i;

	param.coord1 = read_vec(&line);
	param.normal = read_vec(&line);
	param.size1 = read_float(&line);
	param.color = read_color(&line);
	i = -1;
	while (++i < 6)
	{
		data.id = 0;
		data.coord1 = add_vector(
				mult_vector(param.size1 / 2, dir[i]),param.coord1);
		data.normal = dir[i];//a modifier
		data.size1 = param.size1;
		data.color = param.color;
		if (add_newsquaretolst(&(obj->lst_square), creat_square(data)))
			return (1);
	}
	return (0);
}
