/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 09:45:31 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/10 19:46:18 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_texture(t_all *s)
{
	s->texture[0].img = mlx_xpm_file_to_image(s->cp.mlx.mlx, s->parse.no_path,
			&s->cp.parse.width_window_size, &s->cp.parse.height_window_size);
	s->texture[0].addr = (int *)mlx_get_data_addr(s->texture[0].img,
			&s->cp.mlx.b_per_pixel, &s->cp.mlx.line_length, &s->cp.mlx.endian);
	s->texture[1].img = mlx_xpm_file_to_image(s->cp.mlx.mlx, s->parse.so_path,
			&s->cp.parse.width_window_size, &s->cp.parse.height_window_size);
	s->texture[1].addr = (int *)mlx_get_data_addr(s->texture[1].img,
			&s->cp.mlx.b_per_pixel, &s->cp.mlx.line_length, &s->cp.mlx.endian);
	s->texture[2].img = mlx_xpm_file_to_image(s->cp.mlx.mlx, s->parse.we_path,
			&s->cp.parse.width_window_size, &s->cp.parse.height_window_size);
	s->texture[2].addr = (int *)mlx_get_data_addr(s->texture[2].img,
			&s->cp.mlx.b_per_pixel, &s->cp.mlx.line_length, &s->cp.mlx.endian);
	s->texture[3].img = mlx_xpm_file_to_image(s->cp.mlx.mlx, s->parse.ea_path,
			&s->cp.parse.width_window_size, &s->cp.parse.height_window_size);
	s->texture[3].addr = (int *)mlx_get_data_addr(s->texture[3].img,
			&s->cp.mlx.b_per_pixel, &s->cp.mlx.line_length, &s->cp.mlx.endian);
}

void	draw_tex(t_all *s)
{
	s->rc.texy = (int)s->rc.texpos & (TEXHEIGHT - 1);
	s->rc.texpos += s->rc.step;
	if (s->rc.side == 1 && s->rc.raydiry < 0)
		s->mlx.addr[s->axe.y * s->mlx.line_length / 4 + s->axe.x]
			= s->texture[0].addr[s->rc.texy
			* s->cp.mlx.line_length / 4 + s->rc.texx];
	else if (s->rc.side == 1 && s->rc.raydiry > 0)
		s->mlx.addr[s->axe.y * s->mlx.line_length / 4 + s->axe.x]
			= s->texture[1].addr[s->rc.texy
			* s->cp.mlx.line_length / 4 + s->rc.texx];
	else if (s->rc.side == 0 && s->rc.raydirx < 0)
		s->mlx.addr[s->axe.y * s->mlx.line_length / 4 + s->axe.x]
			= s->texture[2].addr[s->rc.texy
			* s->cp.mlx.line_length / 4 + s->rc.texx];
	else if (s->rc.side == 0 && s->rc.raydirx > 0)
		s->mlx.addr[s->axe.y * s->mlx.line_length / 4 + s->axe.x]
			= s->texture[3].addr[s->rc.texy
			* s->cp.mlx.line_length / 4 + s->rc.texx];
	else
		s->mlx.addr[s->axe.y * s->mlx.line_length / 4 + s->axe.x]
			= 0x00ffBBff;
	s->axe.y++;
}

void	drawline_tex(t_all *s)
{
	s->axe.y = 0;
	drawline(s);
	while (s->axe.y <= s->rc.drawend)
		draw_tex(s);
	drawline(s);
}

void	set_rc_var(t_all *s)
{
	s->rc.camerax = 2 * (float)s->axe.x / (float)W_WINDOW - 1;
	s->rc.raydirx = s->boy.dir.x + s->boy.plane.x * s->rc.camerax;
	s->rc.raydiry = s->boy.dir.y + s->boy.plane.y * s->rc.camerax;
	s->rc.mapx = (int)s->boy.pos.x;
	s->rc.mapy = (int)s->boy.pos.y;
	s->rc.deltadistx = fabs(1 / s->rc.raydirx);
	s->rc.deltadisty = fabs(1 / s->rc.raydiry);
	s->rc.hit = 0;
}

void	rc_step_and_dist(t_all *s)
{
	if (s->rc.raydirx < 0)
	{
		s->rc.stepx = -1;
		s->rc.sidedistx = (s->boy.pos.x - s->rc.mapx) * s->rc.deltadistx;
	}
	else
	{
		s->rc.stepx = 1;
		s->rc.sidedistx = (s->rc.mapx + 1.0 - s->boy.pos.x) * s->rc.deltadistx;
	}
	if (s->rc.raydiry < 0)
	{
		s->rc.stepy = -1;
		s->rc.sidedisty = (s->boy.pos.y - s->rc.mapy) * s->rc.deltadisty;
	}
	else
	{
		s->rc.stepy = 1;
		s->rc.sidedisty = (s->rc.mapy + 1.0 - s->boy.pos.y) * s->rc.deltadisty;
	}
}
