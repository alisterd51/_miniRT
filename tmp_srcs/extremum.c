/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extremum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:26:19 by anclarma          #+#    #+#             */
/*   Updated: 2020/11/29 23:44:24 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** RETURN VALUE
**	Retourne la valeur la plus haute parmi a et b
*/

double	max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

/*
** RETURN VALUE
**	Retourne la valeur la plus basse parmi a et b
*/

double	min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}
