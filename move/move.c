/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 09:26:53 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/17 10:30:18 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int		ismovable(char c)
{
	return ((c == '0' || c == 'N' || c == 'W' || c == 'S' || c == 'E'));
}

void	oui(t_all *s)
{
	int i;

	i = 0;
	while (i < s->parse.width_window_size)
	{
		float cameraX = 2 * (float)i / (float)s->parse.width_window_size - 1; //x-coordinate in camera space
		float rayDirX = s->boy.dir.x + s->boy.plane.x * cameraX;
		float rayDirY = s->boy.dir.y + s->boy.plane.y * cameraX;
		//which box of the map we're in
		int mapX = (int)s->boy.pos.x;
		int mapY = (int)s->boy.pos.y;

		//length of ray from current position to next x or y-side
		float sideDistX;
		float sideDistY;

		//length of ray from one x or y-side to next x or y-side
		float deltaDistX = fabs(1 / rayDirX);
		float deltaDistY = fabs(1 / rayDirY);
		float perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
		stepX = -1;
		sideDistX = (s->boy.pos.x - mapX) * deltaDistX;
		}
		else
		{
        stepX = 1;
        sideDistX = (mapX + 1.0 - s->boy.pos.x) * deltaDistX;
		}
		if(rayDirY < 0)
		{
        stepY = -1;
        sideDistY = (s->boy.pos.y - mapY) * deltaDistY;
		}
		else
		{
        stepY = 1;
        sideDistY = (mapY + 1.0 - s->boy.pos.y) * deltaDistY;
		}
		//perform DDA
		while (hit == 0)
		{
		//jump to nuext map sqare, OR in x-direction, OR in y-direction
		if(sideDistX < sideDistY)
		 {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
		}
		else
		{
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
		}
		//Check if ray has hit a wall
		if(s->map.map[mapY][mapX] == '1' || s->map.map[mapY][mapX] == '2') hit = 1;
		}


		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if(side == 0) perpWallDist = (mapX - s->boy.pos.x + (1 - stepX) / 2) / rayDirX;
		else          perpWallDist = (mapY - s->boy.pos.y + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(s->parse.height_window_size / perpWallDist);

		lineHeight = (float)lineHeight / (1.25 *( (float)s->parse.height_window_size / (float)s->parse.width_window_size));

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + s->parse.height_window_size / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + s->parse.height_window_size / 2;
		if(drawEnd >= s->parse.height_window_size)drawEnd = s->parse.height_window_size - 1;

     //choose wall color
      /* int color;
      switch(s->map.map[mapY][mapX])
      {
        case 1:  color = 0x00ff0000;    break; //red
        case 2:  color = 0x0000ff00;  break; //green
        case 3:  color = 0x000000ff;   break; //blue
        case 4:  color = 0x00ffffff;  break; //white
        default: color = 0x00ffff00; break; //yellow
      }
 */

/* color = 0x0032a852;
color = 0x00a83240; */
	int color;
	if(side == 1 && rayDirY < 0 )
		color = 0x00ff0000;
	else if(side == 1 && rayDirY >= 0 )
		color = 0x0000ff00;
	else if(side == 0 && rayDirX < 0 )
		color = 0x000000ff;
	else if(side == 0 && rayDirX >= 0 )
		color = 0x00ffff00;
	else
		color = 0x00000000;
	//give x and y sides different brightness
    /* if(side == 1) {color = color / 2;} */

    //draw the pixels of the stripe as a vertical line
    printline(i, drawStart, drawEnd, color, s);
		i++;
	}
}

void	forward(t_all *s)
{
	s->mlx.img = mlx_new_image(s->mlx.mlx, s->parse.width_window_size, s->parse.height_window_size);
	s->mlx.addr = mlx_get_data_addr(s->mlx.img, &s->mlx.bits_per_pixel, &s->mlx.line_length, &s->mlx.endian);
	if(ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x + s->boy.dir.x * 0.1)]))
		s->boy.pos.x = s->boy.pos.x + s->boy.dir.x * 0.1;
	if(ismovable(s->map.map[(int)(s->boy.pos.y + s->boy.dir.y * 0.1)][(int)(s->boy.pos.x)]))
		s->boy.pos.y = s->boy.pos.y + s->boy.dir.y * 0.1;
	printf("\ntest x = %f\n",(s->boy.pos.x  + s->boy.dir.x * 0.1 ));
	printf("\ntest y = %f\n",(s->boy.pos.y ));
	printf("s->boy.pos.x %f\n", s->boy.pos.x);
	printf("s->boy.pos.y %f\n", s->boy.pos.y);
	/* printmap(s);
	printboy(s); */
	printback(s);
	oui(s);
}

void	backward(t_all *s)
{
	s->mlx.img = mlx_new_image(s->mlx.mlx, s->parse.width_window_size, s->parse.height_window_size);
	s->mlx.addr = mlx_get_data_addr(s->mlx.img, &s->mlx.bits_per_pixel, &s->mlx.line_length, &s->mlx.endian);
	if(ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x + -(s->boy.dir.x * 0.1))]))
		s->boy.pos.x = s->boy.pos.x + -(s->boy.dir.x * 0.1);
	if(ismovable(s->map.map[(int)(s->boy.pos.y + -(s->boy.dir.y * 0.1))][(int)(s->boy.pos.x)]))
		s->boy.pos.y = s->boy.pos.y + -(s->boy.dir.y * 0.1);
	printf("s->boy.pos.x %f\n", s->boy.pos.x);
	printf("s->boy.pos.y %f\n", s->boy.pos.y);
	/* printmap(s);
	printboy(s); */
	printback(s);
	oui(s);
}

void	leftward(t_all *s)
{
	s->mlx.img = mlx_new_image(s->mlx.mlx, s->parse.width_window_size, s->parse.height_window_size);
	s->mlx.addr = mlx_get_data_addr(s->mlx.img, &s->mlx.bits_per_pixel, &s->mlx.line_length, &s->mlx.endian);
	if(ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x + (s->boy.dir.y * 0.1))]))
		s->boy.pos.x = s->boy.pos.x + (s->boy.dir.y * 0.1);
	if(ismovable(s->map.map[(int)(s->boy.pos.y - (s->boy.dir.x * 0.1))][(int)(s->boy.pos.x)]))
		s->boy.pos.y = s->boy.pos.y - (s->boy.dir.x * 0.1);
	printf("s->boy.pos.x %f\n", s->boy.pos.x);
	printf("s->boy.pos.y %f\n", s->boy.pos.y);
	/* printmap(s);
	printboy(s); */
	printback(s);
	oui(s);
}
void	rightward(t_all *s)
{
	s->mlx.img = mlx_new_image(s->mlx.mlx, s->parse.width_window_size, s->parse.height_window_size);
	s->mlx.addr = mlx_get_data_addr(s->mlx.img, &s->mlx.bits_per_pixel, &s->mlx.line_length, &s->mlx.endian);
	if(ismovable(s->map.map[(int)(s->boy.pos.y)][(int)(s->boy.pos.x - (s->boy.dir.y * 0.1))]))
		s->boy.pos.x = s->boy.pos.x - (s->boy.dir.y * 0.1);
	if(ismovable(s->map.map[(int)(s->boy.pos.y + (s->boy.dir.x * 0.1))][(int)(s->boy.pos.x)]))
		s->boy.pos.y = s->boy.pos.y + (s->boy.dir.x * 0.1);
	printf("s->boy.pos.x %f\n", s->boy.pos.x);
	printf("s->boy.pos.y %f\n", s->boy.pos.y);
	/* printmap(s);
	printboy(s); */
	printback(s);
	oui(s);
}

void	dirright(t_all *s)
{
	float oldDirX = s->boy.dir.x;
	s->boy.dir.x = s->boy.dir.x * cos(0.08) - s->boy.dir.y * sin(0.08);
	s->boy.dir.y = oldDirX * sin(0.08) + s->boy.dir.y * cos(0.08);
	float oldPlaneX = s->boy.plane.x;
	s->boy.plane.x = s->boy.plane.x * cos(0.08) - s->boy.plane.y * sin(0.08);
	s->boy.plane.y = oldPlaneX * sin(0.08) + s->boy.plane.y * cos(0.08);
	printf("s->boy.dir.x %f\n", s->boy.dir.x);
	printf("s->boy.dir.y %f\n", s->boy.dir.y);
	/* printmap(s);
	printboy(s); */
	printback(s);
	oui(s);
}

void	dirleft(t_all *s)
{
	float oldDirX = s->boy.dir.x;
	s->boy.dir.x = s->boy.dir.x * cos(-0.08) - s->boy.dir.y * sin(-0.08);
	s->boy.dir.y = oldDirX * sin(-0.08) + s->boy.dir.y * cos(-0.08);
	float oldPlaneX = s->boy.plane.x;
	s->boy.plane.x = s->boy.plane.x * cos(-0.08) - s->boy.plane.y * sin(-0.08);
	s->boy.plane.y = oldPlaneX * sin(-0.08) + s->boy.plane.y * cos(-0.08);
	printf("s->boy.dir.x %f\n", s->boy.dir.x);
	printf("s->boy.dir.y %f\n", s->boy.dir.y);
	/* printmap(s);
	printboy(s); */
	printback(s);
	oui(s);
}




