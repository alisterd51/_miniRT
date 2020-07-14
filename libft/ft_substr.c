/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:23:49 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/07 10:43:41 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	i = 0;
	if (!(dst = malloc(sizeof(char) * (len + 1))) || !s)
		return (NULL);
	if (start < ft_strlen(s))
		while (s[start + i] && i < len)
		{
			dst[i] = s[start + i];
			i++;
		}
	dst[i] = '\0';
	return (dst);
}
