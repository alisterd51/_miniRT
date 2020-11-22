/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:08:14 by antoine           #+#    #+#             */
/*   Updated: 2020/11/22 01:32:26 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
*/
int	read_line_to_int(char **line)
{
	int	ret;

	while (ft_isspace(**line))
		(*line)++;
	ret = ft_atoi(*line);
	if (**line == '+' || **line == '-')
		(*line)++;
	while (ft_isdigit(**line))
		(*line)++;
	return (ret);
}
