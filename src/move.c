/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 09:26:53 by gefaivre          #+#    #+#             */
/*   Updated: 2021/04/14 12:42:26 by gefaivre         ###   ########.fr       */
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
		[(int)(s->boy.pos.x + s->boy.dir.x * 0.1)]))
		s->boy.pos.x = s->boy.pos.x + s->boy.dir.x * 0.1;
	if(ismovable(s->map.map[(int)(s->boy.pos.y + s->boy.dir.y * 0.1)]
		[(int)(s->boy.pos.x)]))
		s->boy.pos.y = s->boy.pos.y + s->boy.dir.y * 0.1;
	oui(s);
}

void	backward(t_all *s)
{
	if(ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x +
		-(s->boy.dir.x * 0.1))]))
		s->boy.pos.x = s->boy.pos.x + -(s->boy.dir.x * 0.1);
	if(ismovable(s->map.map[(int)(s->boy.pos.y + -(s->boy.dir.y * 0.1))]
		[(int)(s->boy.pos.x)]))
		s->boy.pos.y = s->boy.pos.y + -(s->boy.dir.y * 0.1);
	oui(s);
}

void	leftward(t_all *s)
{
	if(ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x +
		(s->boy.dir.y * 0.1))]))
		s->boy.pos.x = s->boy.pos.x + (s->boy.dir.y * 0.1);
	if(ismovable(s->map.map[(int)(s->boy.pos.y - (s->boy.dir.x * 0.1))]
		[(int)(s->boy.pos.x)]))
		s->boy.pos.y = s->boy.pos.y - (s->boy.dir.x * 0.1);
	oui(s);
}
void	rightward(t_all *s)
{
	if(ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x -
		(s->boy.dir.y * 0.1))]))
		s->boy.pos.x = s->boy.pos.x - (s->boy.dir.y * 0.1);
	if(ismovable(s->map.map[(int)(s->boy.pos.y + (s->boy.dir.x * 0.1))]
		[(int)(s->boy.pos.x)]))
		s->boy.pos.y = s->boy.pos.y + (s->boy.dir.x * 0.1);
	oui(s);
}


