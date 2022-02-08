/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 09:47:17 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/08 16:54:04 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

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
