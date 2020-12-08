/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:06:45 by anclarma          #+#    #+#             */
/*   Updated: 2020/12/08 15:33:49 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "lst_obj.h"
#include "exit_err.h"
#include "check_file.h"
#include "libft.h"

static int	parse_line1(char *line, t_obj *obj)
{
	if (*line == 'R' && ft_isspace(*(line + 1)))
		init_res(line + 1, obj);
	else if (*line == 'A' && ft_isspace(*(line + 1)))
		init_amb_light(line + 1, obj);
	else if (*line == 'c' && ft_isspace(*(line + 1)))
		init_lst_cam(line + 1, obj);
	else if (*line == 'l' && ft_isspace(*(line + 1)))
		init_lst_light(line + 1, obj);
	else
		return (0);
	return (1);
}

static int	parse_line2(char *line, t_obj *obj)
{
	if (*line == 's' && *(line + 1) == 'p' && ft_isspace(*(line + 2)))
		init_lst_sphere(line + 2, obj);
	else if (*line == 'p' && *(line + 1) == 'l' && ft_isspace(*(line + 2)))
		init_lst_plane(line + 2, obj);
	else if (*line == 's' && *(line + 1) == 'q' && ft_isspace(*(line + 2)))
		init_lst_square(line + 2, obj);
	else if (*line == 'c' && *(line + 1) == 'y' && ft_isspace(*(line + 2)))
		init_lst_cylinder(line + 2, obj);
	else if (*line == 't' && *(line + 1) == 'r' && ft_isspace(*(line + 2)))
		init_lst_triangle(line + 2, obj);
	else if (*line == 'c' && *(line + 1) == 'u' && ft_isspace(*(line + 2)))
		init_lst_cube(line + 2, obj);
	else if (*line == 'p' && *(line + 1) == 'y' && ft_isspace(*(line + 2)))
		init_lst_pyramid(line + 2, obj);
	else if (*line == 'c' && *(line + 1) == 'o' && ft_isspace(*(line + 2)))
		init_lst_cone(line + 2, obj);
	else
		return (0);
	return (1);
}

static void	parse_line(char *line, t_obj *obj)
{
	if (!line)
		return (exit_errcode(ERROR_LINE));
	else if (*line == '#' || !*line)
		return ;
	else if (!*(line + 1))
		return (exit_errcode(ERROR_LINE));
	else if (parse_line1(line, obj))
		return ;
	else if (!*(line + 2))
		return (exit_errcode(ERROR_LINE));
	else if (parse_line2(line, obj))
		return ;
	else
		return (exit_errcode(UNRECOGNIZED_LINE));
}

void		parsing(char *param, t_obj *obj)
{
	int		fd;
	int		ret_gnl;
	char	*line;

	if (check_file_ext(param, "rt"))
		return (exit_errcode(NOT_RT_FILE));
	fd = open(param, O_RDONLY);
	if (fd == -1)
		return (exit_errcode(OPEN_ERROR));
	ret_gnl = get_next_line(fd, &line);
	while (ret_gnl)
	{
		parse_line(line, obj);
		free(line);
		ret_gnl = get_next_line(fd, &line);
	}
	if (ret_gnl == -1)
		return (exit_errcode(GNL_ERROR));
	parse_line(line, obj);
	free(line);
	if (close(fd))
		return (exit_errcode(CLOSE_ERROR));
}
