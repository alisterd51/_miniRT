/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:55:19 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/07 10:42:49 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*dst;

	dst = NULL;
	if (!*s && !c)
		return ((char *)s);
	if (!c)
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == c)
			dst = (char *)s;
		++s;
	}
	return (dst);
}
