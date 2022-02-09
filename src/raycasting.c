/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 09:44:09 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/09 15:36:17 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	raycasting_2(t_all *s)
{
	s->rc.drawEnd = s->rc.lineHeight / 2 + H_WINDOW / 2;
	if (s->rc.drawEnd >= H_WINDOW)
		s->rc.drawEnd = H_WINDOW - 1;
	s->rc.texNum = s->map.map[s->rc.mapY][s->rc.mapX] - 1;
	if (s->rc.side == 0)
		s->rc.wallX = s->boy.pos.y + s->rc.perpWallDist * s->rc.rayDirY;
	else
		s->rc.wallX = s->boy.pos.x + s->rc.perpWallDist * s->rc.rayDirX;
	s->rc.wallX -= floor((s->rc.wallX));
	s->rc.texX = (int)(s->rc.wallX * 64);
	if ((s->rc.side == 0 && s->rc.rayDirX > 0)
		|| (s->rc.side == 1 && s->rc.rayDirY < 0))
		s->rc.texX = 64 - s->rc.texX - 1;
	s->rc.step = 1.0 * TEXHEIGHT / s->rc.lineHeight;
	s->rc.texPos = (s->rc.drawStart - H_WINDOW
			/ 2 + s->rc.lineHeight / 2) * s->rc.step;
	drawline_tex(s);
	s->axe.x++;
}

void	raycasting(t_all *s)
{
	s->axe.x = 0;
	while (s->axe.x < W_WINDOW)
	{
		set_rc_var(s);
		rc_step_and_dist(s);
		rc_hit(s);
		if (s->rc.side == 0)
			s->rc.perpWallDist = (s->rc.mapX - s->boy.pos.x
					+ (1 - s->rc.stepX) / 2) / s->rc.rayDirX;
		else
			s->rc.perpWallDist = (s->rc.mapY - s->boy.pos.y
					+ (1 - s->rc.stepY) / 2) / s->rc.rayDirY;
		s->rc.lineHeight = (int)(H_WINDOW
				/ s->rc.perpWallDist);
		s->rc.lineHeight = (float)s->rc.lineHeight / (1.25 *(
					(float)H_WINDOW
					/ (float)W_WINDOW));
		s->rc.drawStart = -s->rc.lineHeight
			/ 2 + H_WINDOW / 2;
		if (s->rc.drawStart < 0)
			s->rc.drawStart = 0;
		raycasting_2(s);
	}
	mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->mlx.img, 0, 0);
}
