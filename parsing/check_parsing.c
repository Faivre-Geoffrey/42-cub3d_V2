/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:23:34 by gefaivre          #+#    #+#             */
/*   Updated: 2021/04/20 09:44:39 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_map(t_all *s)
{
	int i;
	int j;

	i = 1;
	while (i < s->map.size.y + 3)
	{
		j = 1;
		while(j < s->map.size.x + 3)
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
			if(s->map.map[i][j] != '0'  && s->map.map[i][j] != '1' &&
			s->map.map[i][j] != '2' && s->map.map[i][j] != ' ' && !is_start_pos(s->map.map[i][j]))
			{
				printf("oui\n");
				printf("x = %i, y = %i\n", j, i);
				printf("map[x,y] = {%c}\n", s->map.map[i][j]);
				return (-1);
			}
			if (s->map.map[i][j] == '2')
				s->parse.numsprite++;
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
	if (s->start.count > 1 || s->start.count < 1)
	{
		printf("Map must contain one start position please\n");
		return (-1);
	}
	return (1);
}

int		set_sprite(t_all *s)
{
	int i;
	int j;
	int x;

	x = 0;


	printf("s->parse.numsprite = %i\n", s->parse.numsprite);


	s->sprite = (t_sprite *)malloc(sizeof(t_sprite) * s->parse.numsprite);
	if (s->sprite == NULL)
	{
		printf("non\n");


	}
	printf("oui1\n");

	i = 0;
	while (i < s->map.size.y + 4)
	{
		j = 0;
		while(j < s->map.size.x + 4)
		{
			if (s->map.map[i][j] == '2')
			{
				s->sprite[x].x = j;
				s->sprite[x].y = i;
				x++;
			}
			j++;
		}
		i++;
	}

	printf("oui2\n");
	return (1);
}

int	check_path_texture_2(char *str)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("fd = %i\n", fd);
		close(fd);
		return (-1);
	}

	close(fd);
	return (0);
}

int	check_path_texture(t_all *s)
{
	if (s->parse.NO_path == NULL || s->parse.EA_path == NULL ||
	s->parse.SO_path == NULL || s->parse.WE_path == NULL ||
	s->parse.S_path == NULL)
	{
		printf("Bad number of texture\n");
		return (-1);
	}


	if (check_path_texture_2(s->parse.NO_path) == -1 ||
	check_path_texture_2(s->parse.WE_path) == -1 ||
	check_path_texture_2(s->parse.SO_path) == -1 ||
	check_path_texture_2(s->parse.EA_path) == -1 ||
	check_path_texture_2(s->parse.S_path) == -1)
	{
		printf("Bad path texture\n");
		return (-1);
	}
	return (1);

}



int		check_parsing(t_all *s)
{
	return (check_map(s) | check_start_pos(s) | set_sprite(s) | check_path_texture(s));
}
