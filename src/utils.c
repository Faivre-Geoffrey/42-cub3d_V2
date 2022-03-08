/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:05:54 by gefaivre          #+#    #+#             */
/*   Updated: 2022/03/08 14:30:15 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ismovable(char c)
{
	return ((c == '0' || c == 'N' || c == 'W' || c == 'S' || c == 'E'));
}

void	ft_fuck_up_fonction(void *i)
{
	return ((void)(i));
}

void	print_list(t_all *s)
{
	while (s->list)
	{
		printf("%p\n", s->list->content);
		s->list = s->list->next;
	}
}

void	print_map(t_all *s)
{
	int	y;
	int	x;

	y = 0;
	while (y < s->map.size.y + 4)
	{
		x = 0;
		while (x < s->map.size.x + 4)
		{
			printf("%c", s->map.map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

int	is_start_pos(char c)
{
	return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}
