/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 09:44:09 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/08 18:05:03 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



void	oui(t_all *s)
{

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
		drawline_tex(s);
		s->spr.zbuffer[s->axe.x] = s->rc.perpWallDist;
		s->axe.x++;
	}
	
	for(int i = 0; i < s->parse.numsprite; i++)
    {
      s->spr.spriteOrder[i] = i;
      s->spr.spriteDistance[i] = ((s->boy.pos.x - s->sprite[i].x) * (s->boy.pos.x - s->sprite[i].x) + (s->boy.pos.y - s->sprite[i].y) * (s->boy.pos.y - s->sprite[i].y)); //sqrt not taken, unneeded
    }

	int x = 0;
	for (int i = 0; i < s->parse.numsprite - 1; i++)
	{
		if (s->spr.spriteDistance[s->spr.spriteOrder[i]] < s->spr.spriteDistance[s->spr.spriteOrder[i + 1]])
		{
			x = s->spr.spriteOrder[i];
			s->spr.spriteOrder[i] = s->spr.spriteOrder[i + 1];
			s->spr.spriteOrder[i + 1] = x;
			i = -1;
		}
	}

	for(int i = 0; i < s->parse.numsprite; i++)
    {
      double spriteX = s->sprite[s->spr.spriteOrder[i]].x - s->boy.pos.x + 0.5;
      double spriteY = s->sprite[s->spr.spriteOrder[i]].y - s->boy.pos.y + 0.5;


      double invDet = 1.0 / (s->boy.plane.x * s->boy.dir.y - s->boy.dir.x * s->boy.plane.y);
      double transformX = invDet * (s->boy.dir.y * spriteX - s->boy.dir.x * spriteY);
      double transformY = invDet * (-s->boy.plane.y * spriteX + s->boy.plane.x * spriteY);

      int spriteScreenX = (int)(s->parse.width_window_size / 2) * (1 + transformX / transformY);

      
      int vMoveScreen = (int)(vMove / transformY);

      int spriteHeight = abs((int)(s->parse.height_window_size / (transformY))) / vDiv;
      int drawStartY = -spriteHeight / 2 + s->parse.height_window_size / 2 + vMoveScreen;
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 + s->parse.height_window_size / 2 + vMoveScreen;
      if(drawEndY >= s->parse.height_window_size) drawEndY = s->parse.height_window_size - 1;


      int spriteWidth = abs( (int) (s->parse.height_window_size / (transformY))) / uDiv;
      int drawStartX = -(spriteWidth) / 2 + spriteScreenX;
      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= s->parse.width_window_size)
      drawEndX = s->parse.width_window_size - 1;


      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * 64 / spriteWidth) / 256;

        if(transformY > 0 && stripe > 0 && stripe < s->parse.width_window_size && transformY < s->spr.zbuffer[stripe])
        for(int y = drawStartY; y < drawEndY; y++)
        {
          int d = (y-vMoveScreen) * 256 - s->parse.height_window_size * 128 + spriteHeight * 128;
          int texY = ((d * texHeight) / spriteHeight) / 256;
		   if (stripe == drawStartX && y == drawStartY) 
		   s->texture[4].addr[texY * s->cp.mlx.line_length / 4 + texX] = s->texture[4].addr[texY * s->cp.mlx.line_length / 4 + texX];
        	if ((s->texture[4].addr[texY * s->cp.mlx.line_length / 4 + texX]) != -16777216)
			{
          		s->mlx.addr[y * s->mlx.line_length / 4 + stripe] =
				s->texture[4].addr[texY * s->cp.mlx.line_length / 4 + texX] ;
			}
        }
      }
    }
	
	mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->mlx.img, 0, 0);
}
