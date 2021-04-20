/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 09:45:31 by gefaivre          #+#    #+#             */
/*   Updated: 2021/04/19 12:29:55 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#define texHeight 64

void	set_texture(t_data texture[5], t_all *cp, t_all *s)
{
	texture[0].img = mlx_xpm_file_to_image(cp->mlx.mlx, s->parse.NO_path,
	&cp->parse.width_window_size, &cp->parse.height_window_size);
	texture[0].addr = (int *)mlx_get_data_addr(texture[0].img,
	&cp->mlx.bits_per_pixel, &cp->mlx.line_length, &cp->mlx.endian);
	texture[1].img = mlx_xpm_file_to_image(cp->mlx.mlx, s->parse.SO_path,
	&cp->parse.width_window_size, &cp->parse.height_window_size);
	texture[1].addr = (int *)mlx_get_data_addr(texture[1].img,
	&cp->mlx.bits_per_pixel, &cp->mlx.line_length, &cp->mlx.endian);
	texture[2].img = mlx_xpm_file_to_image(cp->mlx.mlx, s->parse.WE_path,
	&cp->parse.width_window_size, &cp->parse.height_window_size);
	texture[2].addr = (int *)mlx_get_data_addr(texture[2].img,
	&cp->mlx.bits_per_pixel, &cp->mlx.line_length, &cp->mlx.endian);
	texture[3].img = mlx_xpm_file_to_image(cp->mlx.mlx, s->parse.EA_path,
	&cp->parse.width_window_size, &cp->parse.height_window_size);
	texture[3].addr = (int *)mlx_get_data_addr(texture[3].img,
	&cp->mlx.bits_per_pixel, &cp->mlx.line_length, &cp->mlx.endian);
	texture[4].img = mlx_xpm_file_to_image(cp->mlx.mlx, s->parse.S_path,
	&cp->parse.width_window_size, &cp->parse.height_window_size);
	texture[4].addr = (int *)mlx_get_data_addr(texture[4].img,
	&cp->mlx.bits_per_pixel, &cp->mlx.line_length, &cp->mlx.endian);
}

void	drawline_tex(t_data *texture, t_all *s,t_all *cp)
{
	s->axe.y = 0;
	drawline(s);
	while( s->axe.y <= s->rc.drawEnd )
	{
		s->rc.texY = (int)s->rc.texPos & texHeight - 1;
		s->rc.texPos += s->rc.step;
		if(s->rc.side == 1 && s->rc.rayDirY < 0 )
			s->mlx.addr[s->axe.y * s->mlx.line_length / 4 + s->axe.x ] =
			texture[0].addr[s->rc.texY * cp->mlx.line_length / 4 + s->rc.texX];
		else if(s->rc.side == 1 && s->rc.rayDirY > 0 )
			s->mlx.addr[s->axe.y * s->mlx.line_length / 4 + s->axe.x ] =
			texture[1].addr[s->rc.texY * cp->mlx.line_length / 4 + s->rc.texX];
		else if(s->rc.side == 0 && s->rc.rayDirX < 0 )
			s->mlx.addr[s->axe.y * s->mlx.line_length / 4 + s->axe.x ] =
			texture[2].addr[s->rc.texY * cp->mlx.line_length / 4 + s->rc.texX];
		else if(s->rc.side == 0 && s->rc.rayDirX > 0 )
			s->mlx.addr[s->axe.y * s->mlx.line_length / 4 + s->axe.x ] =
			texture[3].addr[s->rc.texY * cp->mlx.line_length / 4 + s->rc.texX];
		else
			s->mlx.addr[s->axe.y * s->mlx.line_length / 4 + s->axe.x ] =
			0x00ffBBff;
		s->axe.y++;
	}
	drawline(s);
}

void	set_rc_var(t_all *s)
{
	s->rc.cameraX = 2 * (float)s->axe.x /
	(float)s->parse.width_window_size - 1;
	s->rc.rayDirX = s->boy.dir.x + s->boy.plane.x * s->rc.cameraX;
	s->rc.rayDirY = s->boy.dir.y + s->boy.plane.y * s->rc.cameraX;
	s->rc.mapX = (int)s->boy.pos.x;
	s->rc.mapY = (int)s->boy.pos.y;
	s->rc.deltaDistX = fabs(1 / s->rc.rayDirX);
	s->rc.deltaDistY = fabs(1 / s->rc.rayDirY);
	s->rc.hit = 0;
}
void	rc_step_and_dist(t_all *s)
{
	if(s->rc.rayDirX < 0)
	{
		s->rc.stepX = -1;
		s->rc.sideDistX = (s->boy.pos.x - s->rc.mapX) * s->rc.deltaDistX;
	}
	else
	{
		s->rc.stepX = 1;
		s->rc.sideDistX = (s->rc.mapX + 1.0 - s->boy.pos.x) * s->rc.deltaDistX;
	}
	if(s->rc.rayDirY < 0)
	{
		s->rc.stepY = -1;
		s->rc.sideDistY = (s->boy.pos.y - s->rc.mapY) * s->rc.deltaDistY;
	}
	else
	{
		s->rc.stepY = 1;
		s->rc.sideDistY = (s->rc.mapY + 1.0 - s->boy.pos.y) * s->rc.deltaDistY;
	}
}

void	rc_hit(t_all *s)
{
	while (s->rc.hit == 0)
	{
			if(s->rc.sideDistX < s->rc.sideDistY)
			{
				s->rc.sideDistX += s->rc.deltaDistX;
				s->rc.mapX += s->rc.stepX;
				s->rc.side = 0;
			}
			else
			{
				s->rc.sideDistY += s->rc.deltaDistY;
				s->rc.mapY += s->rc.stepY;
				s->rc.side = 1;
			}
			if(s->map.map[s->rc.mapY][s->rc.mapX] == '1')
				s->rc.hit = 1;
	}
}
