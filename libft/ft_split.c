/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 00:15:46 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/07 10:38:38 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbstr(char const *str, char charset)
{
	int		y;
	int		nb;

	y = 0;
	nb = 0;
	while (str[y])
	{
		if (!(str[y] == charset) && str[y])
		{
			nb++;
			while (!(str[y] == charset) && str[y])
				y++;
		}
		else
			y++;
	}
	return (nb);
}

static char	*ft_strdupmod(char const *str, char charset)
{
	char	*dest;
	int		i;

	i = 0;
	while (!(str[i] == charset) && str[i])
		i++;
	if (!(dest = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (!(str[i] == charset) && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**ft_freetab(char **dst, int nu)
{
	while (nu--)
		free(dst[nu]);
	free(dst);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**dst;
	int		i;
	int		y;
	int		nbmot;

	if (!s)
		return (NULL);
	nbmot = ft_nbstr(s, c);
	if (!(dst = malloc(sizeof(char *) * (nbmot + 1))))
		return (NULL);
	i = -1;
	y = 0;
	while (++i < nbmot)
	{
		while (s[y] == c && s[y])
			y++;
		if (!(dst[i] = ft_strdupmod(s + y, c)))
			return (ft_freetab(dst, i));
		while (!(s[y] == c) && s[y])
			y++;
	}
	dst[i] = NULL;
	return (dst);
}
