/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 09:46:00 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/16 15:21:21 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define UP_KEY		126
# define DOWN_KEY	125
# define LEFT_KEY	123
# define RIGHT_KEY	124
# define R_KEY		15
# define ESC_KEY	53

int	deal_mouse(int button, int x, int y, void *param);
int	deal_key(int key, void *param);

#endif
