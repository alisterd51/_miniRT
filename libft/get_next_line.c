/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:08:06 by anclarma          #+#    #+#             */
/*   Updated: 2020/03/13 14:48:10 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_read(char *buf[512], int fd, int bs)
{
	char	*buffer;
	char	*swap;
	int		i;

	buffer = malloc(bs + 1 * sizeof(char));
	i = bs + 1;
	while (i > 0)
		*(buffer + --i) = 0;
	i = read(fd, buffer, bs);
	if (!buf[fd])
	{
		buf[fd] = malloc(1);
		*buf[fd] = '\0';
	}
	swap = buf[fd];
	buf[fd] = ft_strjoin(swap, buffer);
	free(swap);
	free(buffer);
	return (i <= 0 ? i : 1);
}

int		get_next_line(int fd, char **line)
{
	static	char	*buf[512];
	char			*tmp;
	int				line_len;
	int				eof;

	eof = 1;
	while (!ft_strchr(buf[fd], '\n') && eof > 0)
		eof = ft_read(buf, fd, GNL_BUFFER);
	if (eof >= 0)
	{
		if (eof == 0)
			line_len = ft_strchr(buf[fd], '\0') - buf[fd];
		else
			line_len = ft_strchr(buf[fd], '\n') - buf[fd];
		if (!(*line = malloc((line_len + 1) * sizeof(char))))
			return (-1);
		ft_memcpy(*line, buf[fd], line_len + 1);
		if (eof > 0)
			*(ft_strchr(*line, '\n')) = '\0';
		tmp = eof == 0 ? NULL : ft_strdup(ft_strchr(buf[fd], '\n') + 1);
		free(buf[fd]);
		buf[fd] = eof == 0 ? NULL : tmp;
	}
	return (eof);
}
