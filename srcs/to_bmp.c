/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 22:20:42 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/31 13:39:15 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "libft.h"
#include "exit_err.h"

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

void	ft_tobmp(t_mlx *mlx, const char *name)
{
	int		fd;
	int		mod;
	int		size;
	char	*bitmap_file;

	fd = open(name, O_CREAT | O_WRONLY, S_IRWXU);
	if (fd == -1)
		return (exit_errcode(OPEN_BMP_ERROR));
	size = 14 + 40 + mlx->y_size * mlx->x_size * 4;
	mod = 8 - (size % 8);
	if (!(bitmap_file = (char *)malloc(sizeof(char) * (size + mod))))
		return (exit_errcode(MALLOC_ERROR));
	bitmap_file_header(bitmap_file, size + mod);
	dib_header(bitmap_file + 14, mlx->x_size, -(mlx->y_size));
	if (write(fd, bitmap_file, 54) == -1
			|| write(fd, mlx->image, mlx->y_size * mlx->x_size * 4) == -1)
		return (exit_errcode(WRITE_TO_BMP_ERROR));
	free(bitmap_file);
	if (close(fd) == -1)
		return (exit_errcode(CLOSE_BMP_ERROR));
}
