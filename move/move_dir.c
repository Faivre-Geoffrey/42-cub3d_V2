/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 09:47:17 by gefaivre          #+#    #+#             */
/*   Updated: 2021/05/06 13:56:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	dirright(t_all *s)
{
	float oldDirX = s->boy.dir.x;
	s->boy.dir.x = s->boy.dir.x * cos(0.08) - s->boy.dir.y * sin(0.08);
	s->boy.dir.y = oldDirX * sin(0.08) + s->boy.dir.y * cos(0.08);
	float oldPlaneX = s->boy.plane.x;
	s->boy.plane.x = s->boy.plane.x * cos(0.08) - s->boy.plane.y * sin(0.08);
	s->boy.plane.y = oldPlaneX * sin(0.08) + s->boy.plane.y * cos(0.08);
	oui(s);
}

void	dirleft(t_all *s)
{
	float oldDirX = s->boy.dir.x;
	s->boy.dir.x = s->boy.dir.x * cos(-0.08) - s->boy.dir.y * sin(-0.08);
	s->boy.dir.y = oldDirX * sin(-0.08) + s->boy.dir.y * cos(-0.08);
	float oldPlaneX = s->boy.plane.x;
	s->boy.plane.x = s->boy.plane.x * cos(-0.08) - s->boy.plane.y * sin(-0.08);
	s->boy.plane.y = oldPlaneX * sin(-0.08) + s->boy.plane.y * cos(-0.08);
	oui(s);
}
