/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 09:26:53 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/09 14:00:25 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#define texHeight 64

int		ismovable(char c)
{
	return ((c == '0' || c == 'N' || c == 'W' || c == 'S' || c == 'E'));
}

void	forward(t_all *s)
{
	if(ismovable(s->map.map[(int)(s->boy.pos.y)]
		[(int)(s->boy.pos.x + s->boy.dir.x * Vspeed)]))
		s->boy.pos.x = s->boy.pos.x + s->boy.dir.x * Vspeed;
	if(ismovable(s->map.map[(int)(s->boy.pos.y + s->boy.dir.y * Vspeed)]
		[(int)(s->boy.pos.x)]))
		s->boy.pos.y = s->boy.pos.y + s->boy.dir.y * Vspeed;
	raycasting(s);
}

void	backward(t_all *s)
{
	if(ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x +
		-(s->boy.dir.x * Vspeed))]))
		s->boy.pos.x = s->boy.pos.x + -(s->boy.dir.x * Vspeed);
	if(ismovable(s->map.map[(int)(s->boy.pos.y + -(s->boy.dir.y * Vspeed))]
		[(int)(s->boy.pos.x)]))
		s->boy.pos.y = s->boy.pos.y + -(s->boy.dir.y * Vspeed);
	raycasting(s);
}

void	leftward(t_all *s)
{
	if(ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x +
		(s->boy.dir.y * Vspeed))]))
		s->boy.pos.x = s->boy.pos.x + (s->boy.dir.y * Vspeed);
	if(ismovable(s->map.map[(int)(s->boy.pos.y - (s->boy.dir.x * Vspeed))]
		[(int)(s->boy.pos.x)]))
		s->boy.pos.y = s->boy.pos.y - (s->boy.dir.x * Vspeed);
	raycasting(s);
}
void	rightward(t_all *s)
{
	if(ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x -
		(s->boy.dir.y * Vspeed))]))
		s->boy.pos.x = s->boy.pos.x - (s->boy.dir.y * Vspeed);
	if(ismovable(s->map.map[(int)(s->boy.pos.y + (s->boy.dir.x * Vspeed))]
		[(int)(s->boy.pos.x)]))
		s->boy.pos.y = s->boy.pos.y + (s->boy.dir.x * Vspeed);
	raycasting(s);
}


