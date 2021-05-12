/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 08:07:02 by gefaivre          #+#    #+#             */
/*   Updated: 2021/05/12 15:31:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_pp(t_all *s)
{
	int i = 0;
	ft_lstclear(&s->list, free);
	while (i < s->map.size.y +4 )
	{
		free(s->map.map[i]);
		i++;
	}
	free(s->map.map);
	free(s->parse.line);
	free(s->spr.zbuffer);
	free(s->spr.spriteDistance);
	free(s->spr.spriteOrder);
	mlx_destroy_image(s->mlx.mlx, s->mlx.img);


	exit(0);
	return (0);
}

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
	s->boy.dirleft = 0;
	s->boy.dirright = 0;
	s->boy.forward = 0;
	s->boy.backward = 0;
	s->boy.leftward = 0;
	s->boy.rightward = 0;
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
		ft_pp(s);
	else if (key == W)
		forward(s);
	else if (key == S)
		backward(s);
	else if (key == A)
		leftward(s);
	else if (key == D)
		rightward(s);
	else if (key == LEFT)
		dirleft(s);
	else if (key == RIGHT)
		dirright(s);
	
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

int		ft_key_press(int keycode, t_all *s)
{
	if (keycode == W)
		s->boy.forward = 1;
	else if (keycode == S)
		s->boy.backward = 1;
	else if (keycode == A)
		s->boy.leftward = 1;
	else if (keycode == D)
		s->boy.rightward = 1;
	else if (keycode == LEFT)
		s->boy.dirleft = 1;
	else if (keycode == RIGHT)
		s->boy.dirright = 1;
	else if (keycode == ESC)
		ft_pp(s);
	
	return (1);
}

int		ft_key_release(int keycode, t_all *s)
{
	if (keycode == W)
		s->boy.forward = 0;
	else if (keycode == S)
		s->boy.backward = 0;
	else if (keycode == A)
		s->boy.leftward = 0;
	else if (keycode == D)
		s->boy.rightward = 0;
	else if (keycode == LEFT)
		s->boy.dirleft = 0;
	else if (keycode == RIGHT)
		s->boy.dirright = 0;
	else if (keycode == ESC)
		ft_pp(s);
	return (1);
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
		if (second_arg(av[2]) == -1)
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
	s.cp.mlx = s.mlx;
	s.cp.parse = s.parse;
	set_texture(&s);
	s.spr.zbuffer = malloc(sizeof(double) * s.parse.width_window_size);
	s.spr.spriteOrder = malloc(sizeof(int) * s.parse.numsprite);
	s.spr.spriteDistance = malloc(sizeof(double) * s.parse.numsprite);
	oui(&s);
	mlx_hook(s.mlx.mlx_win, 33, 1L << 17, ft_pp, &s);
	mlx_hook(s.mlx.mlx_win, 2, 1L << 0, ft_key_press, &s);
	mlx_loop_hook(s.mlx.mlx, gigi, &s);
	mlx_hook(s.mlx.mlx_win, 3, 1L << 1, ft_key_release, &s);
	mlx_loop(s.mlx.mlx); 
	return (0);
}
