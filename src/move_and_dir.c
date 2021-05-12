/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:38:37 by user42            #+#    #+#             */
/*   Updated: 2021/05/12 14:53:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

#define Vdir 0.1
#define texHeight 64
#define Vspeed 0.1

int gigi5(t_all *s)
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
	oui(s);
	return (1);
}

int gigi4(t_all *s)
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
	gigi5(s);
	return (1);
}


int	gigi3(t_all *s)
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
	gigi4(s);
	return (1);
}

int	gigi2(t_all *s)
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
	gigi3(s);
	return (1);
}

int gigi1(t_all *s)
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
	gigi2(s);
	return (1);
}

int	gigi(t_all *s)
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
	gigi1(s);
	return (1);
}




	
	
	
	
