/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tobmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 22:20:42 by anclarma          #+#    #+#             */
/*   Updated: 2020/11/22 22:57:58 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "libft.h"

void	fill_oct(char *str, int data)
{
	str[0] = (unsigned char)data;
	str[1] = (unsigned char)(data >> 8);
	str[2] = (unsigned char)(data >> 16);
	str[3] = (unsigned char)(data >> 24);
}

void	bitmap_file_header(char *bitmap_file, int size)
{
	ft_bzero(bitmap_file, 14);
	bitmap_file[0] = 'B';
	bitmap_file[1] = 'M';
	fill_oct(bitmap_file + 2, size);
	fill_oct(bitmap_file + 10, 54);
}

void	dib_header(char *bitmap_file, int width, int height)
{
	ft_bzero(bitmap_file, 40);
	fill_oct(bitmap_file, 40);
	fill_oct(bitmap_file + 4, width);
	fill_oct(bitmap_file + 8, height);
	fill_oct(bitmap_file + 12, 1);
	fill_oct(bitmap_file + 14, 32);
	fill_oct(bitmap_file + 20, width * height * 4);
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
	dib_header(bitmap_file + 14, mlx->width, -(mlx->height));
	write(fd, bitmap_file, 54);
	write(fd, mlx->image, mlx->height * mlx->width * 4);
	free(bitmap_file);
	close(fd);
	return (0);
}
