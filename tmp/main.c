/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:43:51 by anclarma          #+#    #+#             */
/*   Updated: 2020/10/17 14:41:16 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "struct.h"

int	main(int ac, char **av)
{
	t_obj	obj;

	init_obj(obj);
	if (ac != 2)
	{
		write(2, "error\n", 6);
		return (1);
	}
	parsing(av[1], obj);
	print_obj(obj);
	return (0);
}
