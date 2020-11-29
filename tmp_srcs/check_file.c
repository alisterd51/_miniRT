/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 00:08:19 by antoine           #+#    #+#             */
/*   Updated: 2020/11/29 23:32:39 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** RETURN VALUE
** 	if extenstion is not detected in end of filename check_file_ext return 1
** 	else return 0
*/

int	check_file_ext(char *filename, char *ext)
{
	int	i;

	i = 0;
	while (filename[i + 1])
		i++;
	while (i >= 0 && filename[i] != '.')
		i--;
	if (i >= 0 && !ft_strcmp(filename + i + 1, ext))
		return (0);
	return (1);
}
