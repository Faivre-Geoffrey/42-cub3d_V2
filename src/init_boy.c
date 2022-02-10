/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_boy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:18:21 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/10 19:39:17 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_boy_n(t_all *s)
{
	s->boy.dir.y = -1;
	s->boy.dir.x = 0;
	s->boy.plane.y = 0;
	s->boy.plane.x = 0.66;
}

void	init_boy_s(t_all *s)
{
	s->boy.dir.y = 1;
	s->boy.dir.x = 0;
	s->boy.plane.y = 0;
	s->boy.plane.x = -0.66;
}

void	init_boy_e(t_all *s)
{
	s->boy.dir.y = 0;
	s->boy.dir.x = 1;
	s->boy.plane.y = 0.66;
	s->boy.plane.x = 0;
}

void	init_boy_w(t_all *s)
{
	s->boy.dir.y = 0;
	s->boy.dir.x = -1;
	s->boy.plane.y = -0.66;
	s->boy.plane.x = 0;
}

void	init_boy(t_all *s)
{
	s->parse.diviseur = W_WINDOW / s->map.size.x;
	s->boy.pos.x = s->start.pos.x + 0.5;
	s->boy.pos.y = s->start.pos.y + 0.5;
	if (s->start.nsew == 'N')
		init_boy_n(s);
	else if (s->start.nsew == 'S')
		init_boy_s(s);
	else if (s->start.nsew == 'E')
		init_boy_e(s);
	else if (s->start.nsew == 'W')
		init_boy_w(s);
}
