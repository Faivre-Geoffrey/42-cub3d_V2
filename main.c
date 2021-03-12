/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 08:07:02 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/12 13:49:20 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	init(t_all *s)
{
	s->list = NULL;
}

void	mlx_init_full(t_all *s)
{
	s->mlx.mlx = mlx_init();
	s->mlx.mlx_win = mlx_new_window(s->mlx.mlx, s->parse.width_window_size , s->parse.height_window_size, "Hello world!");
	s->mlx.img = mlx_new_image(s->mlx.mlx, s->parse.width_window_size, s->parse.height_window_size);
	s->mlx.addr = mlx_get_data_addr(s->mlx.img, &s->mlx.bits_per_pixel, &s->mlx.line_length, &s->mlx.endian);
}

int		ft_key(int key, t_all *s)
{

	if (key == ESC)
		exit(0);
	if (key == W)
		{

			s->mlx.img = mlx_new_image(s->mlx.mlx, s->parse.width_window_size, s->parse.height_window_size);
			s->mlx.addr = mlx_get_data_addr(s->mlx.img, &s->mlx.bits_per_pixel, &s->mlx.line_length, &s->mlx.endian);
			s->boy.pos.x = s->boy.pos.x + s->boy.dir.x * 0.1;
			s->boy.pos.y = s->boy.pos.y + s->boy.dir.y * 0.1;
			printf("s->boy.pos.x %f\n", s->boy.pos.x);
			printf("s->boy.pos.y %f\n", s->boy.pos.y);
			printmap(s);
			printboy(s);
		}
	if (key == S)
		{
			s->mlx.img = mlx_new_image(s->mlx.mlx, s->parse.width_window_size, s->parse.height_window_size);
			s->mlx.addr = mlx_get_data_addr(s->mlx.img, &s->mlx.bits_per_pixel, &s->mlx.line_length, &s->mlx.endian);
			s->boy.pos.x = s->boy.pos.x + -(s->boy.dir.x * 0.1);
			s->boy.pos.y = s->boy.pos.y + -(s->boy.dir.y * 0.1);
			printf("s->boy.pos.x %f\n", s->boy.pos.x);
			printf("s->boy.pos.y %f\n", s->boy.pos.y);
			printmap(s);
			printboy(s);
		}
		if (key == LEFT)
		{
			float oldDirX = s->boy.dir.x;
			s->boy.dir.x = s->boy.dir.x * cos(0.1) - s->boy.dir.y * sin(-0.1);
			s->boy.dir.y = oldDirX * sin(-0.1) + s->boy.dir.y * cos(-0.1);
			/* float oldPlaneX = planeX;
			planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
			planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed); */
			printf("s->boy.dir.x %f\n", s->boy.dir.x);
			printf("s->boy.dir.y %f\n", s->boy.dir.y);
			printmap(s);
			printboy(s);
		}
		if (key == RIGHT)
		{
			float oldDirX = s->boy.dir.x;
			s->boy.dir.x = s->boy.dir.x * cos(-0.1) - s->boy.dir.y * sin(0.1);
			s->boy.dir.y = oldDirX * sin(0.1) + s->boy.dir.y * cos(0.1);
			/* float oldPlaneX = planeX;
			planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
			planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed); */
			printf("s->boy.dir.x %f\n", s->boy.dir.x);
			printf("s->boy.dir.y %f\n", s->boy.dir.y);
			printmap(s);
			printboy(s);
		}

		mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->mlx.img, 0, 0);
	return (1);
}

void	init_boy(t_all *s)
{
	s->parse.diviseur = s->parse.width_window_size / s->map.size.x;
	s->boy.pos.x = s->start.pos.x;
	s->boy.pos.y = s->start.pos.y;
	s->boy.dir.y = -1;
	s->boy.dir.x = 0;
	s->boy.plane.y = 1;
	s->boy.plane.x = 1;


}

void	printboy(t_all *s)
{
	s->axe.x = s->boy.pos.x * s->parse.diviseur - (2 * s->parse.diviseur) + (s->parse.diviseur / 2) - 5;
	s->axe.y = s->boy.pos.y * s->parse.diviseur - (2 * s->parse.diviseur) + (s->parse.diviseur / 2) - 5;

	square_put(s, 10, 0x0042F5A1);
}

int		main()
{
	t_all s;

	init(&s);
	parsing(&s);
	check_parsing(&s);
	init_boy(&s);
	mlx_init_full(&s);



	mlx_hook(s.mlx.mlx_win, 2, 0, ft_key, &s);



	mlx_loop(s.mlx.mlx);

/*	printf("%s\n",s.parse.EA_path);
	printf("%s\n",s.parse.NO_path);
	printf("%s\n",s.parse.S_path);
	printf("%s\n",s.parse.SO_path);
	printf("%s\n",s.parse.WE_path);
	printf("%d\n",s.parse.rgb_F);
	printf("%d\n",s.parse.rgb_C);
	printf("%d\n",s.map.size.x);
	printf("%d\n",s.map.size.y); */



	return (0);
}
