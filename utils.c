/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:05:54 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/10 11:06:53 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_list(t_all *s)
{
	while (s->list)
	{
		printf("%s\n", s->list->content);
		s->list = s->list->next;
	}
}

void	print_map(t_all *s)
{
	int y;
	int x;

	y = 0;
	while (y < s->map.size.y + 4)
	{
		x = 0;
		while (x < s->map.size.x + 4)
		{
			printf("%c",s->map.map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

int		is_start_pos(char c)
{
	return(c == 'N' ||c == 'E' || c == 'S' || c == 'W');
}
