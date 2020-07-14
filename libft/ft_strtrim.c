/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:22:02 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/07 10:43:06 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	len;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	len = 0;
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	while (s1[len])
		len++;
	while (ft_strchr(set, s1[len]) && *s1)
		len--;
	len++;
	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		dst[i] = s1[i];
	dst[i] = '\0';
	return (dst);
}
