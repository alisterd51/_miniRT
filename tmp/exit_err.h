/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:26:35 by anclarma          #+#    #+#             */
/*   Updated: 2020/11/27 00:44:05 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_ERR_H
# define EXIT_ERR_H

# define MALLOC_ERROR					"1"
# define ERROR_LINE						"2"
# define UNRECOGNIZED_LINE				"3"
# define NOT_RT_FILE					"4"
# define OPEN_ERROR						"5"
# define CLOSE_ERROR					"6"
# define GNL_ERROR						"7"
# define TO_MANY_RES_DECLARATION		"8"
# define RES_ERROR_LINE					"9"
# define TO_MANY_AMB_LIGHT_DECLARATION	"a"
# define AMB_LIGHT_ERROR_LINE			"b"
# define CAM_ERROR_LINE					"c"
# define LIGHT_ERROR_LINE				"d"
# define SPHERE_ERROR_LINE				"e"
# define SQUARE_ERROR_LINE				"f"
# define CYLINDER_ERROR_LINE			"10"
# define TRIANGLE_ERROR_LINE			"11"
# define CONE_ERROR_LINE				"12"
# define CUBE_ERROR_LINE				"13"
# define PYRAMID_ERROR_LINE				"14"

/*
** exit_err.c
*/
void	exit_errcode(char *errcode);

#endif
