/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:26:35 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/05 09:48:11 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_ERR_H
# define EXIT_ERR_H

# define ARGC_ERROR						"nombre d'argument\n"
# define MALLOC_ERROR					"echec malloc\n"
# define ERROR_LINE						"mauvais format de ligne\n"
# define UNRECOGNIZED_LINE				"ligne non reconu\n"
# define NOT_RT_FILE					"nom de fichier incorect:*.rt\n"
# define OPEN_ERROR						"echec open\n"
# define CLOSE_ERROR					"echec close\n"
# define GNL_ERROR						"gnl\n"
# define TO_MANY_RES_DECLARATION		"nombre de R incorect dans le .rt\n"
# define RES_ERROR_LINE					"ligne R incorrect\n"
# define RES_TO_SMALL					"resolution < ou = a 0\n"
# define TO_MANY_AMB_LIGHT_DECLARATION	"nombre de A incorect dans le .rt\n"
# define AMB_LIGHT_ERROR_LINE			"ligne A incorrect\n"
# define NOT_CAM_IN_RT_FILE				"pas de camera declare dans le .rt\n"
# define CAM_ERROR_LINE					"ligne c incorrect\n"
# define LIGHT_ERROR_LINE				"ligne l incorrect\n"
# define PLANE_ERROR_LINE				"ligne pl incorrect\n"
# define SPHERE_ERROR_LINE				"ligne sp incorrect\n"
# define SQUARE_ERROR_LINE				"ligne sq incorrect\n"
# define CYLINDER_ERROR_LINE			"ligne cy incorrect\n"
# define TRIANGLE_ERROR_LINE			"ligne tr incorrect\n"
# define CONE_ERROR_LINE				"ligne co incorrect\n"
# define CUBE_ERROR_LINE				"ligne cu incorrect\n"
# define PYRAMID_ERROR_LINE				"ligne py incorrect\n"

/*
** exit_err.c
*/
void	exit_errcode(char *errcode);

#endif
