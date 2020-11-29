/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:26:35 by anclarma          #+#    #+#             */
/*   Updated: 2020/11/29 17:00:59 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_ERR_H
# define EXIT_ERR_H

# define ARGC_ERROR						"Erreur: nombre d'argument\n"
# define MALLOC_ERROR					"Erreur: echec malloc\n"
# define ERROR_LINE						"Erreur: mauvais format de ligne\n"
# define UNRECOGNIZED_LINE				"Erreur: ligne non reconu\n"
# define NOT_RT_FILE					"Erreur: nom de fichier incorect: *.rt\n"
# define OPEN_ERROR						"Erreur: echec open\n"
# define CLOSE_ERROR					"Erreur: echec close\n"
# define GNL_ERROR						"Erreur: gnl\n"
# define TO_MANY_RES_DECLARATION		"Erreur: nombre de R incorect dans le .rt\n"
# define RES_ERROR_LINE					"Erreur: ligne R incorrect\n"
# define TO_MANY_AMB_LIGHT_DECLARATION	"Erreur: nombre de A incorect dans le .rt\n"
# define AMB_LIGHT_ERROR_LINE			"Erreur: ligne A incorrect\n"
# define CAM_ERROR_LINE					"Erreur: ligne c incorrect\n"
# define LIGHT_ERROR_LINE				"Erreur: ligne l incorrect\n"
# define PLANE_ERROR_LINE				"Erreur: ligne pl incorrect\n"
# define SPHERE_ERROR_LINE				"Erreur: ligne sp incorrect\n"
# define SQUARE_ERROR_LINE				"Erreur: ligne sq incorrect\n"
# define CYLINDER_ERROR_LINE			"Erreur: ligne cy incorrect\n"
# define TRIANGLE_ERROR_LINE			"Erreur: ligne tr incorrect\n"
# define CONE_ERROR_LINE				"Erreur: ligne co incorrect\n"
# define CUBE_ERROR_LINE				"Erreur: ligne cu incorrect\n"
# define PYRAMID_ERROR_LINE				"Erreur: ligne py incorrect\n"

/*
** exit_err.c
*/
void	exit_errcode(char *errcode);

#endif
