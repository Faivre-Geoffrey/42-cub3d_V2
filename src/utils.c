/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:05:54 by gefaivre          #+#    #+#             */
/*   Updated: 2021/05/10 12:46:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void fuck_up_fonction(void *i)
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

void		 pixel_put(t_all *s, int x, int y, int color)
{
	s->mlx.addr[y * s->mlx.line_length / 4 + x]= color;
}

void	square_put(t_all *s, int size, int color)
{
	int x = s->axe.x;
	int y = s->axe.y;
	int x_count = 0;
	int y_count = 0;
	int y_save = y;

	while (x_count < size)
	{
		y_count = 0;
		y = y_save;
		while (y_count < size)
		{
			pixel_put(s, x, y, color);
			y++;
			y_count++;
		}
		x++;
		x_count++;

	}
}

void	printceiling(t_all *s)
{
	int		x = 0;
	int		y = 0;
	while (x < (s->parse.height_window_size / 2))
	{
		y = 0;
		while (y < s->parse.width_window_size)
		{
			pixel_put(s, y, x, s->parse.rgb_C);
			y++;
		}
		x++;

	}

}
void	printfloor(t_all *s)
{
	int		x = s->parse.height_window_size / 2;
	int		y = 0;
	while (x < s->parse.height_window_size)
	{
		y = 0;
		while (y < s->parse.width_window_size)
		{
			pixel_put(s, y, x, s->parse.rgb_F);
			y++;
		}
		x++;

	}

}

void	drawline(t_all *s)
{
	if (s->axe.y == 0)
	{
		while (s->axe.y < s->rc.drawStart)
		{
			pixel_put(s, s->axe.x, s->axe.y, s->parse.rgb_C);
			s->axe.y++;
		}
	}
	else if (s->axe.y == s->rc.drawEnd + 1)
	{
		while(s->axe.y < s->parse.height_window_size)
		{
			pixel_put(s, s->axe.x, s->axe.y, s->parse.rgb_F);
			s->axe.y++;
		}
	}
}

void	printback(t_all *s)
{
	printceiling(s);
	printfloor(s);

}

int		namecheck(char *arg, char *ext)
{
	int size;
	int	i;

	i = 0;
	size = 0;
	while (arg[i] != '\0')
		i++;
	size = ft_strlen(ext);
	while(arg[i] != '.' && i < 0 && size < 0)
	{
		if (arg[i] != ext[size])
			return (-1);

		if (arg[i] == '.' && size != 0)
			return (-1);

		size--;
		i--;
	}
	return (1);
}

