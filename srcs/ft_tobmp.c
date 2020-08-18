/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tobmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 22:20:42 by anclarma          #+#    #+#             */
/*   Updated: 2020/08/18 16:33:56 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "libft.h"

void	bitmap_file_header(char *bitmap_file, int size)
{
	ft_memcpy(bitmap_file, "BM\0\0\0\0RT42\x36\0\0\0", 14);
	ft_memcpy(bitmap_file + 2, &size, 4);
}

void	dib_header(char *bitmap_file, int width, int height)
{
	int	tmp;

	ft_memcpy(bitmap_file, "\x28\0\0\0\0\0\0\0\0\0\0\0\x01\0\x10\0\0\0\0\0\0\0\0\0\x12\x0b\0\0\x12\x0b\0\0\0\0\0\0\0\0\0\0", 40);
	ft_memcpy(bitmap_file + 4, &width, 4);
	ft_memcpy(bitmap_file + 8, &height, 4);
	tmp = width * height * 4;
    ft_memcpy(bitmap_file + 20, &tmp, 4);
}

void	pixel_array(char *bitmap_file, t_mlx *mlx)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mlx->height)
	{
		x = -1;
		while (++x < mlx->width)
		{
			bitmap_file[0] = mlx->image[(mlx->height - y) * mlx->width + x] >> 16;
			bitmap_file[1] = mlx->image[(mlx->height - y) * mlx->width + x] >> 8;
			bitmap_file[2] = mlx->image[(mlx->height - y) * mlx->width + x];
			bitmap_file[3] = 0;
		}
	}
}

int     ft_tobmp(t_mlx *mlx, const char *name)
{
	int		fd;
	int		mod;
	int		size;
	char	*bitmap_file;

	fd = open(name, O_CREAT | O_WRONLY);
	size = 14 + 40 + mlx->height * mlx->width * 4;
	mod = 8 - (size % 8);
	if (!(bitmap_file = (char *)malloc(sizeof(char) * (size + mod))))
		return (-1);
	bitmap_file_header(bitmap_file, size + mod);
	dib_header(bitmap_file + 14, mlx->width, mlx->height);
	//ft_memcpy(bitmap_file + 54, (char *)(mlx->image), mlx->height * mlx->width * 4);
	//ft_bzero(bitmap_file + size, mod);
	//write(fd, bitmap_file, size + mod);
	pixel_array(bitmap_file + 54, mlx);
	write(fd, bitmap_file, 54);
	write(fd, mlx->image, mlx->height * mlx->width * 4);
	free(bitmap_file);
	close(fd);
	return (0);
}
