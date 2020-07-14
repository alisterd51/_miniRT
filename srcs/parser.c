/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 10:27:23 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/13 10:32:02 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "libft.h"
#include "init_obj.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int		parser1(char *line, t_obj *obj)
{
	char	c1;
	char	c2;
	int		error;

	c1 = *line;
	c2 = c1 ? *(line + 1) : 0;
	if (c1 == 'R' && ft_isspace(c2))
		error = init_res(line + 1, obj);
	else if (c1 == 'A' && ft_isspace(c2))
		error = init_amblight(line + 1, obj);
	else if (c1 == 'c' && ft_isspace(c2))
		error = init_cam(line + 1, obj);
	else if (c1 == 'l' && ft_isspace(c2))
		error = init_light(line + 1, obj);
	else if (c1 == 's' && c2 == 'p')
		error = init_sphere(line + 2, obj);
	else if (c1 == 'p' && c2 == 'l')
		error = init_plane(line + 2, obj);
	else if (c1 == 's' && c2 == 'q')
		error = init_square(line + 2, obj);
	else if (c1 == 'c' && c2 == 'y')
		error = init_cylinder(line + 2, obj);
	else if (c1 == 't' && c2 == 'r')
		error = init_triangle(line + 2, obj);
	else
		error = 0;
	return (error);
}

void	parser(char *file, t_obj *obj)
{
	int 	fd;
	int 	ret;
	char	*line;

	init_obj(obj);
	fd = open(file, O_RDONLY);
	ret = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		parser1(line, obj);
		free(line);
	}
	parser1(line, obj);
	free(line);
	close(fd);
}
