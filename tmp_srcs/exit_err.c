/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 00:40:10 by antoine           #+#    #+#             */
/*   Updated: 2020/11/27 17:16:31 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "lst_obj.h"
#include "libft.h"

/*
** DESCRIPTION
** 	print errcode to stderr and exit programme
** NOTA
** 	non teste
*/
void	exit_errcode(char *errcode)
{
	write(2, errcode, ft_strlen(errcode));
	exit(0);
}
