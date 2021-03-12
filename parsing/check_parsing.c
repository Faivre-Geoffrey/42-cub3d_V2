/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:23:34 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/11 14:45:53 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_map(t_all *s)
{
	int i;
	int j;

	i = 0;
	while (i < s->map.size.y + 4)
	{
		j = 0;
		while(j < s->map.size.x + 4)
		{
			if((ft_isdigit(s->map.map[i][j]) && s->map.map[i][j] != '1')|| is_start_pos(s->map.map[i][j]))
			{
				if (s->map.map[i + 1][j] == ' ' || s->map.map[i - 1][j] == ' '
				|| s->map.map[i][j + 1] == ' ' || s->map.map[i][j - 1] == ' ')
				{
					printf("map is not secure\n");
					return (-1);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		check_start_pos(t_all *s)
{
	int i;
	int j;

	i = 0;
	s->start.count = 0;
	while (i < s->map.size.y + 4)
	{
		j = 0;
		while(j < s->map.size.x + 4)
		{
			if(is_start_pos(s->map.map[i][j]))
			{
				s->start.count++;
				s->start.NSEW = s->map.map[i][j];
				s->start.pos.y = i;
				s->start.pos.x = j;
			}
			j++;
		}
		i++;
	}
	if (s->start.count > 1)
	{
		printf("Map must contain one start position please\n");
		return (-1);
	}
	return (1);
}

int		check_parsing(t_all *s)
{
	(void )s;
	check_map(s);
	check_start_pos(s);

	return (1);
}
