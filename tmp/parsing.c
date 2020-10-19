/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:06:45 by anclarma          #+#    #+#             */
/*   Updated: 2020/10/19 17:29:43 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "lst_obj.h"

static void	parse_line(char *line, t_obj *obj)
{
	
}

void		parsing(char *param, t_obj *obj)
{
	int		fd;
	int		ret_gnl;
	char	*line;

	if (check_file_rt(param))
		exit_errcode(NOT_RT_FILE);
	if ((fd = open(param, O_RDONLY)) == -1)
		exit_errcode(OPEN_ERROR);
	while ((ret_gnl = get_next_line(fd, &line)) == 1)
	{
		parse_line(line, obj);
		free(line);
	}
	if (ret_gnl == -1)
		exit_errcode(GNL_ERROR);
	parse_line(line, obj);
	free(line);
	if (close(fd))
		exit_errcode(CLOSE_ERROR);
}
