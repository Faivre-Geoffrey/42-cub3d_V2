/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 08:07:02 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/10 19:24:52 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char *av[])
{
	t_all	s;

	init(&s);
	if (ac < 2 || ac > 3)
		ft_quit(&s, "Error\nBad numbers of args\n");
	map_path(&s, av[1]);
	parsing(&s);
	check_parsing(&s);
	init_boy(&s);
	mlx_init_full(&s);
	s.cp.mlx = s.mlx;
	s.cp.parse = s.parse;
	set_texture(&s);
	raycasting(&s);
	mlx_hook(s.mlx.mlx_win, 33, 1L << 17, red_cross_quit, &s);
	mlx_hook(s.mlx.mlx_win, 2, 1L << 0, ft_key_press, &s);
	mlx_loop_hook(s.mlx.mlx, set_move, &s);
	mlx_hook(s.mlx.mlx_win, 3, 1L << 1, ft_key_release, &s);
	mlx_loop(s.mlx.mlx);
	return (0);
}
