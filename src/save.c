/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:59:33 by user42            #+#    #+#             */
/*   Updated: 2022/02/08 17:13:23 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_header(t_all *s, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * s->parse.width_window_size * s->parse.height_window_size;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &s->parse.width_window_size, 4);
	write(fd, &s->parse.height_window_size, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &s->mlx.bits_per_pixel, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

void	save(t_all *s, char *str)
{
	int	fd;
	int	x;
	int	y;

	if (ft_strncmp(str, "--save", 7) != 0)
		ft_quit(s, "Error\nsecond args must be \"--save\"");
	y = s->parse.width_window_size;
	if ((fd = open("./image.bmp", O_CREAT | O_RDWR)) == -1)
		ft_quit(s, "Error\nCan't create .bmp\n");
	ft_header(s, fd);
	while (y >= 0)
	{
		x = 0;
		while (x < s->parse.height_window_size)
		{
			write(fd, &s->mlx.addr[y * s->mlx.line_length / 4 + x],
				4);
			x++;
		}
		y--;
	}
	system("chmod 777 image.bmp");
	ft_quit(s, "--save ok");
}