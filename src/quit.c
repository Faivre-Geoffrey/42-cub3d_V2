/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:29:46 by user42            #+#    #+#             */
/*   Updated: 2022/03/08 14:21:52 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_gnl(t_all *s)
{
	if (s->parse.line)
	{
		free(s->parse.line);
		s->parse.line = NULL;
	}
	while (s->parse.c_nbr_line < s->parse.nbr_line)
	{
		s->parse.line = get_next_line(s->parse.fd);
		free(s->parse.line);
		s->parse.line = NULL;
		s->parse.c_nbr_line++;
	}
	if (s->parse.line)
	{
		free(s->parse.line);
		s->parse.line = NULL;
	}
	if (s->parse.fd != -1)
		close(s->parse.fd);
}

void	free_path_and_map(t_all *s)
{
	int	i;

	i = 0;
	if (s->list)
		ft_lstclear(&s->list, free);
	if (s->parse.we_path)
		free(s->parse.we_path);
	if (s->parse.ea_path)
		free(s->parse.ea_path);
	if (s->parse.so_path)
		free(s->parse.so_path);
	if (s->parse.no_path)
		free(s->parse.no_path);
	if (s->map.map)
	{
		while (s->map.map[i] && i < s->map.size.y + 4)
		{
			free(s->map.map[i]);
			i++;
		}
		free(s->map.map);
	}
}

void	ft_quit(t_all *s, char *str)
{
	free_gnl(s);
	free_path_and_map(s);
	if (s->mlx.img)
		mlx_destroy_image(s->mlx.mlx, s->mlx.img);
	if (s->texture[0].img)
		mlx_destroy_image(s->mlx.mlx, s->texture[0].img);
	if (s->texture[1].img)
		mlx_destroy_image(s->mlx.mlx, s->texture[1].img);
	if (s->texture[2].img)
		mlx_destroy_image(s->mlx.mlx, s->texture[2].img);
	if (s->texture[3].img)
		mlx_destroy_image(s->mlx.mlx, s->texture[3].img);
	if (s->mlx.mlx_win)
		mlx_destroy_window(s->mlx.mlx, s->mlx.mlx_win);
	if (s->mlx.mlx)
	{
		mlx_destroy_display(s->mlx.mlx);
		free(s->mlx.mlx);
	}
	printf("%s", str);
	exit(0);
}
