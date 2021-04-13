/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 09:44:09 by gefaivre          #+#    #+#             */
/*   Updated: 2021/04/13 09:16:47 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#define texHeight 64
# define NONE 0xFF000000



void	ft_dist_order2(t_all *s)
{
	int i;

	i = -1;
	while (++i < s->spr.nbspr)
	{
		s->spr.order[i] = i;
		s->spr.dist[i] = ((s->boy.pos.x - s->sxy[i].x) *
				(s->boy.pos.x - s->sxy[i].x) + (s->boy.pos.y -
					s->sxy[i].y) * (s->boy.pos.y - s->sxy[i].y));
	}
}

void	ft_dist_order(t_all *s)
{
	int		i;
	int		j;
	double	tmp;

	ft_dist_order2(s);
	i = -1;
	while (++i < s->parse.numsprite)
	{
		j = -1;
		while (++j < s->parse.numsprite - 1)
		{
			if (s->spr.dist[j] < s->spr.dist[j + 1])
			{
				tmp = s->spr.dist[j];
				s->spr.dist[j] = s->spr.dist[j + 1];
				s->spr.dist[j + 1] = tmp;
				tmp = s->spr.order[j];
				s->spr.order[j] = s->spr.order[j + 1];
				s->spr.order[j + 1] = (int)tmp;
			}
		}
	}
}

void	ft_calculs(t_all *s, int i)
{
	s->spr.spritex = s->sxy[s->spr.order[i]].x - s->boy.pos.x;
	s->spr.spritey = s->sxy[s->spr.order[i]].y - s->boy.pos.y;
	s->spr.invdet = 1.0 / (s->boy.plane.x * s->boy.dir.y -
			s->boy.dir.x * s->boy.plane.y);
	s->spr.transformx = s->spr.invdet * (s->boy.dir.y *
			s->spr.spritex - s->boy.dir.x * s->spr.spritey);
	s->spr.transformy = s->spr.invdet * (-s->boy.plane.y *
			s->spr.spritex + s->boy.plane.x * s->spr.spritey);
	s->spr.spritescreenx = (int)((s->parse.width_window_size / 2) * (1 + s->spr.transformx
				/ s->spr.transformy));
	s->spr.spriteheight = abs((int)(s->parse.height_window_size / (s->spr.transformy)));
	s->spr.drawstarty = -s->spr.spriteheight / 2 + s->parse.height_window_size / 2;
	if (s->spr.drawstarty < 0)
		s->spr.drawstarty = 0;
	s->spr.drawendy = s->spr.spriteheight / 2 + s->parse.height_window_size / 2;
	if (s->spr.drawendy >= s->parse.height_window_size)
		s->spr.drawendy = s->parse.height_window_size;
	s->spr.spritewidth = abs((int)(s->parse.height_window_size / (s->spr.transformy)));
	s->spr.drawstartx = -s->spr.spritewidth / 2 + s->spr.spritescreenx;
	if (s->spr.drawstartx < 0)
		s->spr.drawstartx = 0;
	s->spr.drawendx = s->spr.spritewidth / 2 + s->spr.spritescreenx;
	if (s->spr.drawendx >= s->parse.width_window_size)
		s->spr.drawendx = s->parse.width_window_size;
}

void	ft_draw_spr(t_all *s, int y, int texx, int stripe)
{
	int		d;
	int		texy;

	while (y < s->spr.drawendy)
	{
		d = (y) * 256 - s->parse.height_window_size * 128 + s->spr.spriteheight * 128;
		texy = ((d * s->texture[4].height) / s->spr.spriteheight) / 256;
		if (s->texture[4].addr[texy * s->texture[4].line_length / 4 +
				texx] != -16777216)
		{
			s->data.addr[y * s->data.line_length / 4 + stripe] =
				s->texture[4].addr[texy * s->texture[4].line_length /
				4 + texx];
		}
		y++;
	}
}

void	ft_sprite(t_all *s)
{
	int i;
	int y;
	int stripe;
	int texx;

	i = -1;
	ft_dist_order(s);
	while (++i < s->parse.numsprite)
	{
		ft_calculs(s, i);
		stripe = s->spr.drawstartx;
		while (stripe < s->spr.drawendx)
		{
			texx = (int)(256 * (stripe - (-s->spr.spritewidth / 2 +
							s->spr.spritescreenx)) * s->texture[4].width
					/ s->spr.spritewidth) / 256;
			if (s->spr.transformy > 0 && stripe >= 0 && stripe < s->parse.width_window_size
					&& s->spr.transformy < s->spr.zbuffer[stripe])
			{
				y = s->spr.drawstarty;
				ft_draw_spr(s, y, texx, stripe);
			}
			stripe++;
		}
	}
}










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
		drawline_tex(*(&texture), s, cp);
		ft_sprite(s);
		s->axe.x++;
}

void	oui(t_all *s)
{


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
