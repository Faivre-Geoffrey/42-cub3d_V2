/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 08:07:02 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/10 16:23:38 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_all *s)
{
	s->list = NULL;
}

int		main()
{
	t_all s;

	init(&s);
	parsing(&s);
	check_parsing(&s);

	s.mlx.mlx = mlx_init();
	s.mlx.mlx_win = mlx_new_window(s.mlx.mlx, s.parse.width_window_size , s.parse.height_window_size, "Hello world!");
    s.mlx.img = mlx_new_image(s.mlx.mlx, 1920, 1080);
    s.mlx.addr = mlx_get_data_addr(s.mlx.img, &s.mlx.bits_per_pixel, &s.mlx.line_length,
                                 &s.mlx.endian);
    pixel_put(&s, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(s.mlx.mlx, s.mlx.mlx_win, s.mlx.img, 0, 0);
    mlx_loop(s.mlx.mlx);

	printf("%s\n",s.parse.EA_path);
	printf("%s\n",s.parse.NO_path);
	printf("%s\n",s.parse.S_path);
	printf("%s\n",s.parse.SO_path);
	printf("%s\n",s.parse.WE_path);
	printf("%d\n",s.parse.rgb_F);
	printf("%d\n",s.parse.rgb_C);
	printf("%d\n",s.map.size.x);
	printf("%d\n",s.map.size.y);



	return (0);
}
