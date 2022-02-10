/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:23:34 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/10 19:39:17 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_map(t_all *s)
{
	int	i;
	int	j;

	i = 1;
	while (i < s->map.size.y + 3)
	{
		j = 1;
		while (j < s->map.size.x + 3)
		{
			if (ismovable(s->map.map[i][j]))
			{
				if (s->map.map[i + 1][j] == ' ' || s->map.map[i - 1][j] == ' '
				|| s->map.map[i][j + 1] == ' ' || s->map.map[i][j - 1] == ' ')
					ft_quit(s, "Error\nMap is not secure\n");
			}
			j++;
		}
		i++;
	}
}

void	check_start_pos(t_all *s)
{
	int	i;
	int	j;

	i = 0;
	s->start.count = 0;
	while (i < s->map.size.y + 4)
	{
		j = 0;
		while (j < s->map.size.x + 4)
		{
			if (is_start_pos(s->map.map[i][j]))
			{
				s->start.count++;
				s->start.nsew = s->map.map[i][j];
				s->start.pos.y = i;
				s->start.pos.x = j;
			}
			j++;
		}
		i++;
	}
	if (s->start.count != 1)
		ft_quit(s, "Error\nMap must contain one start \
position please (or add a wall)\n");
}

void	check_path_texture_2(t_all *s, char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_quit(s, "Error\nBad path texture\n");
	close(fd);
}

void	check_path_texture(t_all *s)
{
	if (s->parse.no_path == NULL || s->parse.ea_path == NULL
		|| s->parse.so_path == NULL || s->parse.we_path == NULL )
		ft_quit(s, "Error\nBad number of texture\n");
	check_path_texture_2(s, s->parse.no_path);
	check_path_texture_2(s, s->parse.we_path);
	check_path_texture_2(s, s->parse.so_path);
	check_path_texture_2(s, s->parse.ea_path);
}

void	check_parsing(t_all *s)
{
	check_map(s);
	check_start_pos(s);
	check_path_texture(s);
}
