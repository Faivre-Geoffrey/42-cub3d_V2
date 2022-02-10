/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:39:05 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/10 15:16:56 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mlx_init_full(t_all *s)
{
	s->mlx.mlx = mlx_init();
	s->mlx.mlx_win = mlx_new_window(s->mlx.mlx, 1080, 740, "cub3d");
	s->mlx.img = mlx_new_image(s->mlx.mlx, 1080, 740);
	s->mlx.addr = (int *)mlx_get_data_addr(s->mlx.img,
			&s->mlx.b_per_pixel, &s->mlx.line_length, &s->mlx.endian);
}

void	init_boy_value(t_all *s)
{
	s->boy.dirleft = 0;
	s->boy.dirright = 0;
	s->boy.forward = 0;
	s->boy.backward = 0;
	s->boy.leftward = 0;
	s->boy.rightward = 0;
}

void set_null_mx_pointer(t_all *s)
{
	s->texture[0].img = NULL;
	s->texture[1].img = NULL;
	s->texture[2].img = NULL;
	s->texture[3].img = NULL;
	s->mlx.addr = NULL;
	s->mlx.img = NULL;
	s->mlx.mlx = NULL;
	s->mlx.mlx_win = NULL;

}

void	init(t_all *s)
{
	s->list = NULL;
	s->parse.line = NULL;
	s->map.map = NULL;
	
	s->parse.NO_path = NULL;
	s->parse.EA_path = NULL;
	s->parse.SO_path = NULL;
	s->parse.WE_path = NULL;
	s->parse.lastisline = 0;
	s->parse.in_map = 1;
	s->parse.treat_no_path = 0;
	s->parse.treat_so_path = 0;
	s->parse.treat_we_path = 0;
	s->parse.treat_ea_path = 0;
	s->parse.treat_RGB_F = 0;
	s->parse.treat_RGB_C = 0;
	s->parse.spaceinmap = 0;
	init_boy_value(s);
	set_null_mx_pointer(s);
	
}
