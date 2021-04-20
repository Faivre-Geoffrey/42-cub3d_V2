/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 08:07:02 by gefaivre          #+#    #+#             */
/*   Updated: 2021/04/20 09:44:46 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void	init(t_all *s)
{
	s->list = NULL;
	s->parse.height_window_size = 0;
	s->parse.width_window_size = 0;
	s->parse.firstline = 1;
	s->parse.lastisline = 0;

	s->parse.NO_path = NULL;
	s->parse.EA_path = NULL;
	s->parse.SO_path = NULL;
	s->parse.WE_path = NULL;
	s->parse.S_path = NULL;

	s->parse.treat_window_size = 0;
	s->parse.treat_NO_path = 0;
	s->parse.treat_SO_path = 0;
	s->parse.treat_WE_path = 0;
	s->parse.treat_EA_path = 0;
	s->parse.treat_S_path = 0;
	s->parse.treat_RGB_F = 0;
	s->parse.treat_RGB_C = 0;
	s->parse.spaceinmap = 0;
	s->parse.numsprite = 0;
	s->sprite = NULL;
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
	if (s->start.NSEW == 'N')
	{
		s->boy.dir.y = -1;
		s->boy.dir.x = 0;
		s->boy.plane.y = 0;
		s->boy.plane.x = 0.66;
	}
	else if (s->start.NSEW == 'S')
	{
		s->boy.dir.y = 1;
		s->boy.dir.x = 0;
		s->boy.plane.y = 0;
		s->boy.plane.x = -0.66;
	}
	else if (s->start.NSEW == 'E')
	{
		s->boy.dir.y = 0;
		s->boy.dir.x = 1;
		s->boy.plane.y = 0.66;
		s->boy.plane.x = 0;
	}
	else if (s->start.NSEW == 'W')
	{
		s->boy.dir.y = 0;
		s->boy.dir.x = -1;
		s->boy.plane.y = -0.66;
		s->boy.plane.x = 0;
	}
}

void	printboy(t_all *s)
{
	s->axe.x = s->boy.pos.x * s->parse.diviseur - (2 * s->parse.diviseur) ;
	s->axe.y = s->boy.pos.y * s->parse.diviseur - (2 * s->parse.diviseur) ;

	square_put(s, 10, 0x0042F5A1);
}



int		map_path(t_all *s,char *str)
{

	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
			return (-1);
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b' && str[i + 4] == '\0')
	{
		s->parse.map_path = str;
		return (1);
	}
	return (-1);

}

int		second_arg(char *str)
{
	if (ft_strncmp(str, "--save", 7) != 0)
		return -1;
	return 0;
}

int	ft_pp(int key, t_all *s)
{
	exit(0);
	return (0);
}

int		main(int ac, char *av[])
{
	t_all s;

	init(&s);
	if (ac < 2 || ac > 3)
	{
		printf("bad numbers of args\n");
		return (-1);
	}
	if (ac == 3)
		if (second_arg(&s, av[2]) == -1)
		{
			printf("Second args must be \"--save\"\n");
			return (-1);
		}
	if (map_path(&s, av[1]) == -1)
	{
		printf("Bad map_path name\n");
		return (-1);
	}

	if (parsing(&s) == -1)
	{
		printf("\"parsing\" return = [-1]\n");
		return (-1);
	}
	if (check_parsing(&s) == -1)
	{
		printf("\"check_parsing\" return = [-1]\n");
		return (-1);
	}
	init_boy(&s);
	mlx_init_full(&s);
	oui(&s);
	mlx_put_image_to_window(s.mlx.mlx, s.mlx.mlx_win, s.mlx.img, 0, 0);
	mlx_hook(s.mlx.mlx_win, 2, 0, ft_key, &s);
	mlx_hook(s.mlx.mlx_win, 17, 0, ft_pp, &s);
	mlx_loop(s.mlx.mlx);
	return (0);
}
