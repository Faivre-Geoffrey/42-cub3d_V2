/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:38:37 by user42            #+#    #+#             */
/*   Updated: 2022/02/21 17:45:37 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	set_move5(t_all *s)
{
	if (s->boy.rightward == 1)
	{
		if (ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x
			- (s->boy.dir.y * VSPEED))]))
			s->boy.pos.x = s->boy.pos.x - (s->boy.dir.y * VSPEED);
		if (ismovable(s->map.map[(int)(s->boy.pos.y + (s->boy.dir.x * VSPEED))]
			[(int)(s->boy.pos.x)]))
			s->boy.pos.y = s->boy.pos.y + (s->boy.dir.x * VSPEED);
	}
	raycasting(s);
	return (1);
}

int	set_move4(t_all *s)
{
	if (s->boy.leftward == 1)
	{
		if (ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x
			+ (s->boy.dir.y * VSPEED))]))
			s->boy.pos.x = s->boy.pos.x + (s->boy.dir.y * VSPEED);
		if (ismovable(s->map.map[(int)(s->boy.pos.y - (s->boy.dir.x * VSPEED))]
			[(int)(s->boy.pos.x)]))
			s->boy.pos.y = s->boy.pos.y - (s->boy.dir.x * VSPEED);
	}
	set_move5(s);
	return (1);
}

int	set_move3(t_all *s)
{
	if (s->boy.backward == 1)
	{
		if (ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x
			+ -(s->boy.dir.x * VSPEED))]))
			s->boy.pos.x = s->boy.pos.x + -(s->boy.dir.x * VSPEED);
		if (ismovable(s->map.map[(int)(s->boy.pos.y + -(s->boy.dir.y * VSPEED))]
			[(int)(s->boy.pos.x)]))
			s->boy.pos.y = s->boy.pos.y + -(s->boy.dir.y * VSPEED);
	}
	set_move4(s);
	return (1);
}

int	set_move2(t_all *s)
{
	if (s->boy.forward == 1)
	{
		if (ismovable(s->map.map[(int)(s->boy.pos.y)]
			[(int)(s->boy.pos.x + s->boy.dir.x * VSPEED)]))
			s->boy.pos.x = s->boy.pos.x + s->boy.dir.x * VSPEED;
		if (ismovable(s->map.map[(int)(s->boy.pos.y + s->boy.dir.y * VSPEED)]
			[(int)(s->boy.pos.x)]))
			s->boy.pos.y = s->boy.pos.y + s->boy.dir.y * VSPEED;
	}
	set_move3(s);
	return (1);
}
