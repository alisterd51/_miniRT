/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:07:52 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/07 10:41:56 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n - 1 && (unsigned char)s1[i] == (unsigned char)s2[i] && s1[i])
		i++;
	return (i == n ? 0 : (unsigned char)s1[i] - (unsigned char)s2[i]);
}
