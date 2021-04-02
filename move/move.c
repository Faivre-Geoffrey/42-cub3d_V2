/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 09:26:53 by gefaivre          #+#    #+#             */
/*   Updated: 2021/04/02 09:47:35 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#define texHeight 64

int		ismovable(char c)
{
	return ((c == '0' || c == 'N' || c == 'W' || c == 'S' || c == 'E'));
}

void	forward(t_all *s)
{
	if(ismovable(s->map.map[(int)(s->boy.pos.y)]
		[(int)(s->boy.pos.x + s->boy.dir.x * 0.1)]))
		s->boy.pos.x = s->boy.pos.x + s->boy.dir.x * 0.1;
	if(ismovable(s->map.map[(int)(s->boy.pos.y + s->boy.dir.y * 0.1)]
		[(int)(s->boy.pos.x)]))
		s->boy.pos.y = s->boy.pos.y + s->boy.dir.y * 0.1;
	printback(s);
	oui(s);
}

void	backward(t_all *s)
{
	s->mlx.img = mlx_new_image(s->mlx.mlx, s->parse.width_window_size,
		s->parse.height_window_size);
	s->mlx.addr = (int *)mlx_get_data_addr(s->mlx.img, &s->mlx.bits_per_pixel,
		&s->mlx.line_length, &s->mlx.endian);
	if(ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x +
		-(s->boy.dir.x * 0.1))]))
		s->boy.pos.x = s->boy.pos.x + -(s->boy.dir.x * 0.1);
	if(ismovable(s->map.map[(int)(s->boy.pos.y + -(s->boy.dir.y * 0.1))]
		[(int)(s->boy.pos.x)]))
		s->boy.pos.y = s->boy.pos.y + -(s->boy.dir.y * 0.1);
	printback(s);
	oui(s);
}

void	leftward(t_all *s)
{
	s->mlx.img = mlx_new_image(s->mlx.mlx, s->parse.width_window_size,
		s->parse.height_window_size);
	s->mlx.addr = (int *)mlx_get_data_addr(s->mlx.img, &s->mlx.bits_per_pixel,
		&s->mlx.line_length, &s->mlx.endian);
	if(ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x +
		(s->boy.dir.y * 0.1))]))
		s->boy.pos.x = s->boy.pos.x + (s->boy.dir.y * 0.1);
	if(ismovable(s->map.map[(int)(s->boy.pos.y - (s->boy.dir.x * 0.1))]
		[(int)(s->boy.pos.x)]))
		s->boy.pos.y = s->boy.pos.y - (s->boy.dir.x * 0.1);
	printback(s);
	oui(s);
}
void	rightward(t_all *s)
{
	s->mlx.img = mlx_new_image(s->mlx.mlx, s->parse.width_window_size,
		s->parse.height_window_size);
	s->mlx.addr = (int *)mlx_get_data_addr(s->mlx.img, &s->mlx.bits_per_pixel,
		&s->mlx.line_length, &s->mlx.endian);
	if(ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x -
		(s->boy.dir.y * 0.1))]))
		s->boy.pos.x = s->boy.pos.x - (s->boy.dir.y * 0.1);
	if(ismovable(s->map.map[(int)(s->boy.pos.y + (s->boy.dir.x * 0.1))]
		[(int)(s->boy.pos.x)]))
		s->boy.pos.y = s->boy.pos.y + (s->boy.dir.x * 0.1);
	printback(s);
	oui(s);
}


