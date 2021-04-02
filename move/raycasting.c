/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 09:44:09 by gefaivre          #+#    #+#             */
/*   Updated: 2021/04/02 09:47:42 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#define texHeight 64

void	oui_2(t_data *texture, t_all *s,t_all *cp)
{
	if(s->rc.drawEnd >= s->parse.height_window_size)
			s->rc.drawEnd = s->parse.height_window_size - 1;
		s->rc.texNum = s->map.map[s->rc.mapY][s->rc.mapX] - 1;
		if(s->rc.side == 0)
			s->rc.wallX = s->boy.pos.y + s->rc.perpWallDist * s->rc.rayDirY;
		else
			s->rc.wallX = s->boy.pos.x + s->rc.perpWallDist * s->rc.rayDirX;
		s->rc.wallX -= floor((s->rc.wallX));
		s->rc.texX = (int)(s->rc.wallX * 64);
		if((s->rc.side == 0 && s->rc.rayDirX > 0) || (s->rc.side == 1 && s->rc.rayDirY < 0))
			s->rc.texX = 64 - s->rc.texX - 1;
		s->rc.step = 1.0 * texHeight / s->rc.lineHeight;
		s->rc.texPos = (s->rc.drawStart -  s->parse.height_window_size/
		2 + s->rc.lineHeight / 2) * s->rc.step;
		drawline(*(&texture), s, cp);
		s->axe.x++;
}

void	oui(t_all *s)
{
	t_data texture[4];
	t_all cp = *s;

	set_texture(*(&texture), &cp);
	s->axe.x = 0;
	while (s->axe.x < s->parse.width_window_size)
	{
		set_rc_var(s);
		rc_step_and_dist(s);
		rc_hit(s);
		if(s->rc.side == 0)
			s->rc.perpWallDist = (s->rc.mapX - s->boy.pos.x +
			(1 - s->rc.stepX) / 2) / s->rc.rayDirX;
		else
			s->rc.perpWallDist = (s->rc.mapY - s->boy.pos.y +
			(1 - s->rc.stepY) / 2) / s->rc.rayDirY;
		s->rc.lineHeight = (int)(s->parse.height_window_size / s->rc.perpWallDist);
		s->rc.lineHeight = (float)s->rc.lineHeight / (1.25 *(
			(float)s->parse.height_window_size / (float)s->parse.width_window_size));
		s->rc.drawStart = -s->rc.lineHeight / 2 + s->parse.height_window_size / 2;
		if(s->rc.drawStart < 0)
			s->rc.drawStart = 0;
		s->rc.drawEnd = s->rc.lineHeight / 2 + s->parse.height_window_size / 2;
		oui_2(*(&texture), s,&cp);
	}
}
