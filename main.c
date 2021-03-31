/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 08:07:02 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/30 10:20:04 by gefaivre         ###   ########.fr       */
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
	s->mlx.addr = (int *)mlx_get_data_addr(s->mlx.img, &s->mlx.bits_per_pixel, &s->mlx.line_length, &s->mlx.endian);
}

int		ft_key(int key, t_all *s)
{
	if (key == ESC)
		exit(0);
	if (key == W)
		forward(s);
	if (key == S)
		backward(s);
	if (key == A)
		leftward(s);
	if (key == D)
		rightward(s);
	if (key == LEFT)
		dirleft(s);
	if (key == RIGHT)
		dirright(s);
	mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->mlx.img, 0, 0);
	return (1);
}

void	init_boy(t_all *s)
{
	s->parse.diviseur = s->parse.width_window_size / s->map.size.x;
	s->boy.pos.x = s->start.pos.x + 0.5;
	s->boy.pos.y = s->start.pos.y + 0.5;
	s->boy.dir.y = -1;
	s->boy.dir.x = 0;
	s->boy.plane.y = 0;
	s->boy.plane.x = 0.66;


}

void	printboy(t_all *s)
{
	s->axe.x = s->boy.pos.x * s->parse.diviseur - (2 * s->parse.diviseur) ;
	s->axe.y = s->boy.pos.y * s->parse.diviseur - (2 * s->parse.diviseur) ;

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



	/* t_data texture;

	t_all cp = s;




	texture.img = mlx_xpm_file_to_image(s.mlx.mlx, "textures/east.xpm", &cp.parse.width_window_size, &cp.parse.height_window_size);
	texture.addr = (int *)mlx_get_data_addr(texture.img, &cp.mlx.bits_per_pixel, &cp.mlx.line_length, &cp.mlx.endian);



	for(int x = 0; x < 1000; x++)
		for(int y = 0; y < 1000; y++)
		{

			s.mlx.addr[x * s.mlx.line_length / 4 + y ] = texture.addr[x % 64  * cp.mlx.line_length / 4 + y % 64];
		}

	s.axe.x = 100;
	s.axe.y = 100;

	square_put(&s, 10, 0x00ff00ff);



	mlx_put_image_to_window(s.mlx.mlx, s.mlx.mlx_win, s.mlx.img, 0, 0);
	printf("s.mlx.line_length = %d\n", s.mlx.line_length);
	printf("cp.mlx.line_length = %d\n", cp.mlx.line_length); */
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
