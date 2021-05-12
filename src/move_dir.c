/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 09:47:17 by gefaivre          #+#    #+#             */
/*   Updated: 2021/05/12 11:00:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"
#define Vdir 0.2
void	dirright(t_all *s)
{
	float oldDirX = s->boy.dir.x;
	s->boy.dir.x = s->boy.dir.x * cos(Vdir) - s->boy.dir.y * sin(Vdir);
	s->boy.dir.y = oldDirX * sin(Vdir) + s->boy.dir.y * cos(Vdir);
	float oldPlaneX = s->boy.plane.x;
	s->boy.plane.x = s->boy.plane.x * cos(Vdir) - s->boy.plane.y * sin(Vdir);
	s->boy.plane.y = oldPlaneX * sin(Vdir) + s->boy.plane.y * cos(Vdir);
	oui(s);
}

void	dirleft(t_all *s)
{
	float oldDirX = s->boy.dir.x;
	s->boy.dir.x = s->boy.dir.x * cos(-Vdir) - s->boy.dir.y * sin(-Vdir);
	s->boy.dir.y = oldDirX * sin(-Vdir) + s->boy.dir.y * cos(-Vdir);
	float oldPlaneX = s->boy.plane.x;
	s->boy.plane.x = s->boy.plane.x * cos(-Vdir) - s->boy.plane.y * sin(-Vdir);
	s->boy.plane.y = oldPlaneX * sin(-Vdir) + s->boy.plane.y * cos(-Vdir);
	oui(s);
}
