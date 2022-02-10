/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 09:44:09 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/10 19:46:18 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rc_hit(t_all *s)
{
	while (s->rc.hit == 0)
	{
		if (s->rc.sidedistx < s->rc.sidedisty)
		{
			s->rc.sidedistx += s->rc.deltadistx;
			s->rc.mapx += s->rc.stepx;
			s->rc.side = 0;
		}
		else
		{
			s->rc.sidedisty += s->rc.deltadisty;
			s->rc.mapy += s->rc.stepy;
			s->rc.side = 1;
		}
		if (s->map.map[s->rc.mapy][s->rc.mapx] == '1')
			s->rc.hit = 1;
	}
}

void	raycasting_2(t_all *s)
{
	s->rc.drawend = s->rc.lineheight / 2 + H_WINDOW / 2;
	if (s->rc.drawend >= H_WINDOW)
		s->rc.drawend = H_WINDOW - 1;
	s->rc.texnum = s->map.map[s->rc.mapy][s->rc.mapx] - 1;
	if (s->rc.side == 0)
		s->rc.wallx = s->boy.pos.y + s->rc.perpwalldist * s->rc.raydiry;
	else
		s->rc.wallx = s->boy.pos.x + s->rc.perpwalldist * s->rc.raydirx;
	s->rc.wallx -= floor((s->rc.wallx));
	s->rc.texx = (int)(s->rc.wallx * 64);
	if ((s->rc.side == 0 && s->rc.raydirx > 0)
		|| (s->rc.side == 1 && s->rc.raydiry < 0))
		s->rc.texx = 64 - s->rc.texx - 1;
	s->rc.step = 1.0 * TEXHEIGHT / s->rc.lineheight;
	s->rc.texpos = (s->rc.drawstart - H_WINDOW
			/ 2 + s->rc.lineheight / 2) * s->rc.step;
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
			s->rc.perpwalldist = (s->rc.mapx - s->boy.pos.x
					+ (1 - s->rc.stepx) / 2) / s->rc.raydirx;
		else
			s->rc.perpwalldist = (s->rc.mapy - s->boy.pos.y
					+ (1 - s->rc.stepy) / 2) / s->rc.raydiry;
		s->rc.lineheight = (int)(H_WINDOW
				/ s->rc.perpwalldist);
		s->rc.lineheight = (float)s->rc.lineheight / (1.25 *(
					(float)H_WINDOW
					/ (float)W_WINDOW));
		s->rc.drawstart = -s->rc.lineheight
			/ 2 + H_WINDOW / 2;
		if (s->rc.drawstart < 0)
			s->rc.drawstart = 0;
		raycasting_2(s);
	}
	mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->mlx.img, 0, 0);
}
