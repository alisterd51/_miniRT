/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:36:56 by antoine           #+#    #+#             */
/*   Updated: 2020/11/22 17:38:23 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	int_to_char(int value)
{
	if (value <= 0)
		return (0x00);
	if (value >= 255)
		return (0xFF);
	return ((char)value);
}

int		is_not_char(int value)
{
	if (value < 0 || value > 255)
		return (1);
	return (0);
}
