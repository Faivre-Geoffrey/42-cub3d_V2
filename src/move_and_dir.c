/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:38:37 by user42            #+#    #+#             */
/*   Updated: 2022/02/09 14:01:34 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

#define texHeight 64

int set_move5(t_all *s)
{
	if (s->boy.rightward == 1)
	{
		if(ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x -
			(s->boy.dir.y * Vspeed))]))
			s->boy.pos.x = s->boy.pos.x - (s->boy.dir.y * Vspeed);
		if(ismovable(s->map.map[(int)(s->boy.pos.y + (s->boy.dir.x * Vspeed))]
			[(int)(s->boy.pos.x)]))
			s->boy.pos.y = s->boy.pos.y + (s->boy.dir.x * Vspeed);
	}
	raycasting(s);
	return (1);
}

int set_move4(t_all *s)
{
	if (s->boy.leftward == 1)
	{
		if(ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x +
			(s->boy.dir.y * Vspeed))]))
			s->boy.pos.x = s->boy.pos.x + (s->boy.dir.y * Vspeed);
		if(ismovable(s->map.map[(int)(s->boy.pos.y - (s->boy.dir.x * Vspeed))]
			[(int)(s->boy.pos.x)]))
			s->boy.pos.y = s->boy.pos.y - (s->boy.dir.x * Vspeed);
	}
	set_move5(s);
	return (1);
}


int	set_move3(t_all *s)
{
	if (s->boy.backward == 1)
	{
		if(ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x +
			-(s->boy.dir.x * Vspeed))]))
			s->boy.pos.x = s->boy.pos.x + -(s->boy.dir.x * Vspeed);
		if(ismovable(s->map.map[(int)(s->boy.pos.y + -(s->boy.dir.y * Vspeed))]
			[(int)(s->boy.pos.x)]))
			s->boy.pos.y = s->boy.pos.y + -(s->boy.dir.y * Vspeed);
	}
	set_move4(s);
	return (1);
}

int	set_move2(t_all *s)
{
	if (s->boy.forward == 1)
	{
		if(ismovable(s->map.map[(int)(s->boy.pos.y)]
			[(int)(s->boy.pos.x + s->boy.dir.x * Vspeed)]))
			s->boy.pos.x = s->boy.pos.x + s->boy.dir.x * Vspeed;
		if(ismovable(s->map.map[(int)(s->boy.pos.y + s->boy.dir.y * Vspeed)]
			[(int)(s->boy.pos.x)]))
			s->boy.pos.y = s->boy.pos.y + s->boy.dir.y * Vspeed;
	}
	set_move3(s);
	return (1);
}

int set_move1(t_all *s)
{
	
	if (s->boy.dirleft == 1)
	{
		float oldDirX = s->boy.dir.x;
		s->boy.dir.x = s->boy.dir.x * cos(-Vdir) - s->boy.dir.y * sin(-Vdir);
		s->boy.dir.y = oldDirX * sin(-Vdir) + s->boy.dir.y * cos(-Vdir);
		float oldPlaneX = s->boy.plane.x;
		s->boy.plane.x = s->boy.plane.x * cos(-Vdir) - s->boy.plane.y * sin(-Vdir);
		s->boy.plane.y = oldPlaneX * sin(-Vdir) + s->boy.plane.y * cos(-Vdir);
	}
	set_move2(s);
	return (1);
}

int	set_move(t_all *s)
{
    if (s->boy.dirright == 1)
    {
	    float oldDirX = s->boy.dir.x;
	    s->boy.dir.x = s->boy.dir.x * cos(Vdir) - s->boy.dir.y * sin(Vdir);
	    s->boy.dir.y = oldDirX * sin(Vdir) + s->boy.dir.y * cos(Vdir);
	    float oldPlaneX = s->boy.plane.x;
	    s->boy.plane.x = s->boy.plane.x * cos(Vdir) - s->boy.plane.y * sin(Vdir);
	    s->boy.plane.y = oldPlaneX * sin(Vdir) + s->boy.plane.y * cos(Vdir);
    }
	set_move1(s);
	return (1);
}




	
	
	
	
