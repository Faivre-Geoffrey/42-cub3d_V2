/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:46:26 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/09 16:25:27 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_key_press(int keycode, t_all *s)
{
	if (keycode == W)
		s->boy.forward = 1;
	else if (keycode == S)
		s->boy.backward = 1;
	else if (keycode == A)
		s->boy.leftward = 1;
	else if (keycode == D)
		s->boy.rightward = 1;
	else if (keycode == LEFT)
		s->boy.dirleft = 1;
	else if (keycode == RIGHT)
		s->boy.dirright = 1;
	else if (keycode == ESC)
		ft_quit(s, "ESC pressed : \nBYE!!\n");
	return (1);
}

int	ft_key_release(int keycode, t_all *s)
{
	if (keycode == W)
		s->boy.forward = 0;
	else if (keycode == S)
		s->boy.backward = 0;
	else if (keycode == A)
		s->boy.leftward = 0;
	else if (keycode == D)
		s->boy.rightward = 0;
	else if (keycode == LEFT)
		s->boy.dirleft = 0;
	else if (keycode == RIGHT)
		s->boy.dirright = 0;
	return (1);
}

int	red_cross_quit(t_all *s)
{
	ft_quit(s, "BYE!!\n");
	return (0);
}
