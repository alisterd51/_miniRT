/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tobmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 22:20:42 by anclarma          #+#    #+#             */
/*   Updated: 2020/08/16 14:53:00 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

int		ft_tobmp(t_mlx *mlx, char *name)
{
	int		fd;
	char	*bitmap_file_header;
	char	*dib_header;
	char	*pixel_array;

	fd = open(name, O_RDWR);
	bitmap_file_header = "BM\x00\x00\x00\x00RT42\x36\x00\x00\x00";
	dib_header = 

	//BITMAP FILE HEADER
	//magic number
	write(fd, "BM", 2);
	//size
	write(fd, "", 4);
	//id app
	write(fd, "42", 2);
	write(fd, "RT", 2);
	//offset: addresse de depart
	write(fd, "", 4);// si DIB HEADER de 40 octet, 0 + 14 + 40 = 54 soit 0x36

	//DIB HEADER
	//BITMAPINFOHEADER
	//the size of this header
	write(fd, "", 4); //40 0 0 0 ou 0x28 0x00 0x00 0x00
	//the bitmap width in pixels
	write(fd, "", 4); //mlx->width
	//the bitmap height in pixels
	write(fd, "", 4); //mlx->height
	//the number of color planes
	write(fd, "", 2); //1 0
	//the number of bits per pixel, which is the color depth of the image
	write(fd, "", 2); //16 a priori 4 int
	// the compression method being used
	write(fd, "", 4); //a priori 0 0 0 0
	// the image size
	write(fd, "", 4); // ? ?
	// the horizontal resolution of the image
	write(fd, "", 4);
	// the vertical resolution of the image
	write(fd, "", 4);
	// the number of colors in the color palette, or 0 to default to 2n
	write(fd, "", 4);
	// the number of important colors used, or 0 when every color is important
	write(fd, "", 4);
}
