/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 11:21:37 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/09 21:57:06 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "struct.h"

void	render(t_mlx *mlx);
void	prerender(t_mlx *mlx);
void	oversampling(t_mlx *mlx);
void	prerendered(t_mlx *mlx);

#endif
