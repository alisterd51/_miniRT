/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:43:51 by anclarma          #+#    #+#             */
/*   Updated: 2020/10/25 18:15:45 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lst_obj.h"
#include "parsing.h"
#include "exit_err.h"

int	main(int ac, char **av)
{
	t_obj	*obj;

	if (!(obj = init_obj()))
		exit_errcode(MALLOC_ERROR);
	if (ac != 2)
	{
		write(2, "error\n", 6);
		return (1);
	}
	parsing(av[1], obj);
	print_obj(obj);
	free_obj(&obj);
	return (0);
}
