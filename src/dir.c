/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:25:52 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/10 14:26:24 by gefaivre         ###   ########.fr       */
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
		s->boy.dir.x = s->boy.dir.x * cos(-Vdir)
			- s->boy.dir.y * sin(-Vdir);
		s->boy.dir.y = olddirx * sin(-Vdir)
			+ s->boy.dir.y * cos(-Vdir);
		oldplanex = s->boy.plane.x;
		s->boy.plane.x = s->boy.plane.x * cos(-Vdir)
			- s->boy.plane.y * sin(-Vdir);
		s->boy.plane.y = oldplanex * sin(-Vdir)
			+ s->boy.plane.y * cos(-Vdir);
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
		s->boy.dir.x = s->boy.dir.x * cos(Vdir)
			- s->boy.dir.y * sin(Vdir);
		s->boy.dir.y = olddirx * sin(Vdir)
			+ s->boy.dir.y * cos(Vdir);
		oldplanex = s->boy.plane.x;
		s->boy.plane.x = s->boy.plane.x * cos(Vdir)
			- s->boy.plane.y * sin(Vdir);
		s->boy.plane.y = oldplanex * sin(Vdir)
			+ s->boy.plane.y * cos(Vdir);
	}
	set_move1(s);
	return (1);
}
