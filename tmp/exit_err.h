/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:26:35 by anclarma          #+#    #+#             */
/*   Updated: 2020/10/25 18:00:44 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_ERR_H
# define EXIT_ERR_H

# define MALLOC_ERROR				""
# define ERROR_LINE					""
# define UNRECOGNIZED_LINE			""
# define NOT_RT_FILE				""
# define OPEN_ERROR					""
# define CLOSE_ERROR				""
# define GNL_ERROR					""
# define TO_MANY_RES_DECLARATION	""
# define RES_ERROR_LINE				""

/*
** exit_err.c
*/
void	exit_errcode(char *errcode);

#endif
