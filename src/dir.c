/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:25:52 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/10 19:33:23 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	set_move1(t_all *s)
{
	float	olddirx;
	float	oldplanex;

	if (s->boy.dirleft == 1)
	{
		olddirx = s->boy.dir.x;
		s->boy.dir.x = s->boy.dir.x * cos(-VDIR)
			- s->boy.dir.y * sin(-VDIR);
		s->boy.dir.y = olddirx * sin(-VDIR)
			+ s->boy.dir.y * cos(-VDIR);
		oldplanex = s->boy.plane.x;
		s->boy.plane.x = s->boy.plane.x * cos(-VDIR)
			- s->boy.plane.y * sin(-VDIR);
		s->boy.plane.y = oldplanex * sin(-VDIR)
			+ s->boy.plane.y * cos(-VDIR);
	}
	set_move2(s);
	return (1);
}

int	set_move(t_all *s)
{
	float	olddirx;
	float	oldplanex;

	if (s->boy.dirright == 1)
	{
		olddirx = s->boy.dir.x;
		s->boy.dir.x = s->boy.dir.x * cos(VDIR)
			- s->boy.dir.y * sin(VDIR);
		s->boy.dir.y = olddirx * sin(VDIR)
			+ s->boy.dir.y * cos(VDIR);
		oldplanex = s->boy.plane.x;
		s->boy.plane.x = s->boy.plane.x * cos(VDIR)
			- s->boy.plane.y * sin(VDIR);
		s->boy.plane.y = oldplanex * sin(VDIR)
			+ s->boy.plane.y * cos(VDIR);
	}
	set_move1(s);
	return (1);
}
