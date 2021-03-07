/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 00:40:10 by antoine           #+#    #+#             */
/*   Updated: 2021/03/07 14:22:11 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "lst_obj.h"
#include "libft.h"

/*
** DESCRIPTION
** 	print errcode to stderr and exit programme
*/

void	exit_errcode(char *errcode)
{
	ssize_t	ret;

	ret = write(2, "Erreur: ", 9);
	ret = write(2, errcode, ft_strlen(errcode));
	(void)ret;
	exit(1);
}
