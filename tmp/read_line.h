/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:54:10 by anclarma          #+#    #+#             */
/*   Updated: 2020/11/22 17:30:59 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_LINE_H
# define READ_LINE_H

#include "struct.h"

/*
** read_line.c
*/
int			read_line_to_int(char **line);
double		read_line_to_double(char **line);
t_color		read_line_to_color(char **line);
t_vector	read_line_to_vector(char **line);
char		*read_line_to_string(char **line);

#endif
