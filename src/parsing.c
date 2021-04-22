/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 07:16:17 by gefaivre          #+#    #+#             */
/*   Updated: 2021/04/14 14:42:38 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	if (str[i] == '-')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < 9)
		res = (res * 10) + (str[i++] - '0');
	return (res * neg);
}

int		treat_window_size(t_all *s)
{
	int		i;
	i = 0;
	while (!(ft_isdigit(s->parse.line[i])))
		i++;
	if (ft_isdigit(s->parse.line[i]))
	{
		if (ft_atoi(&s->parse.line[i]) > 2560)
			s->parse.width_window_size = 2560;
		else
			s->parse.width_window_size = ft_atoi(&s->parse.line[i]);
	}
	while (ft_isdigit(s->parse.line[i]))
		i++;
	while (!(ft_isdigit(s->parse.line[i])))
		i++;
	if (ft_isdigit(s->parse.line[i]))
	{
		if (ft_atoi(&s->parse.line[i]) > 1440)
			s->parse.height_window_size = 1440;
		else
			s->parse.height_window_size = ft_atoi(&s->parse.line[i]);
	}
	if (s->parse.width_window_size < 3 || s->parse.height_window_size < 3)
	{
		printf("Bad resolution1\n");
		return (-1);
	}
	while (!(ft_isdigit(s->parse.line[i])))
	{
		i++;
		if (ft_isdigit(s->parse.line[i]))
		{
			printf("Bad resolution2\n");
			return (-1);
		}
	}
	return 0;
}

int	is_line_at_map(char *str)
{
	int i;
	int x;


	x = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W' && !ft_isdigit(str[i]))
			return (0);
		if (str[i] == '1' || str[i] == '0')
			x = 1;
		i++;
	}
	if (x == 0)
		return (0);
	return (1);
}

int		treat_line(t_all *s)
{
	printf("line = {%s}\n", s->parse.line);
	if (s->parse.line[0] == 'R' && s->parse.treat_window_size == 0 && s->parse.firstline == 1)
	{
		s->parse.lastisline = 0;
		s->parse.treat_window_size = 1;
		if (treat_window_size(s) == -1)
		{
			printf("\"treat_window_size\" return = [-1]\n");
			return (-1);
		}
		return (0);
	}
	else if (s->parse.line[0] == 'N' && s->parse.line[1] == 'O' && s->parse.treat_NO_path == 0 && s->parse.firstline == 1)
	{
		s->parse.lastisline = 0;
		s->parse.treat_NO_path = 1;
		if (treat_NO_path(s) == -1)
		{
			printf("\"treat_NO_path\" return = [-1]\n");
			return (-1);
		}
		return (0);
	}
	else if (s->parse.line[0] == 'S' && s->parse.line[1] == 'O' && s->parse.treat_SO_path == 0 && s->parse.firstline == 1)
	{
		s->parse.lastisline = 0;
		s->parse.treat_SO_path = 1;
		if (treat_SO_path(s) == -1)
		{
			printf("\"treat_SO_path\" return = [-1]\n");
			return (-1);
		}
		return (0);
	}
	else if (s->parse.line[0] == 'W' && s->parse.line[1] == 'E' && s->parse.treat_WE_path == 0 && s->parse.firstline == 1)
	{
		s->parse.lastisline = 0;
		s->parse.treat_WE_path = 1;
		if (treat_WE_path(s) == -1)
		{
			printf("\"treat_WE_path\" return = [-1]\n");
			return (-1);
		}
		return (0);
	}
	else if (s->parse.line[0] == 'E' && s->parse.line[1] == 'A' && s->parse.treat_EA_path == 0 && s->parse.firstline == 1)
	{
		s->parse.lastisline = 0;
		s->parse.treat_WE_path = 1;
		if (treat_EA_path(s) == -1)
		{
			printf("\"treat_EA_path\" return = [-1]\n");
			return (-1);
		}
		return (0);
	}
	else if (s->parse.line[0] == 'S' && s->parse.treat_S_path == 0 && s->parse.firstline == 1)
	{
		s->parse.lastisline = 0;
		s->parse.treat_S_path = 1;
		if (treat_S_path(s) == -1)
		{
			printf("\"treat_S_path\" return = [-1]\n");
			return (-1);
		}
		return (0);
	}
	else if (s->parse.line[0] == 'F' && s->parse.treat_RGB_F == 0 && s->parse.firstline == 1)
	{
		s->parse.lastisline = 0;
		s->parse.treat_RGB_F = 1;
		if ((s->parse.rgb_F = treat_RGB(s)) == -1)
		{
			printf("\"Treat_RGB\" return = [-1]\n");
			return -1;
		}
		return (0);
	}
	else if (s->parse.line[0] == 'C' && s->parse.treat_RGB_C == 0 && s->parse.firstline == 1)
	{
		s->parse.lastisline = 0;
		s->parse.treat_RGB_C = 1;
		if ((s->parse.rgb_C = treat_RGB(s) )== -1)
		{
			printf("\"Treat_RGB\" return = [-1]\n");
			return -1;
		}
		return (0);
	}
	else if (is_line_at_map(s->parse.line) && s->parse.spaceinmap == 0 && (s->parse.lastisline == 1 || (s->parse.lastisline == 0 && s->parse.firstline == 1)))
	{
		if (s->parse.lastisline == 1 &&  s->parse.spaceinmap == 1)
		{
			printf("Don't break the map in .cub\n");
			return (-1);
		}
		s->parse.firstline = 0;
		s->parse.lastisline = 1;
		make_linked_list(s);
		return (0);
	}


	else if ((int)ft_strlen(s->parse.line) == 0)
	{
		if (s->parse.firstline == 0)
			s->parse.spaceinmap = 1;
		return (0);
	}
	return (-1);
}





int		parsing(t_all *s)
{
	s->parse.line = NULL;
	s->parse.fd = open(s->parse.map_path, __O_DIRECTORY);
	if (s->parse.fd != -1 )
	{
		printf("map_path can't be a directory\n");
		return (-1);
	}
	s->parse.fd = open(s->parse.map_path, O_RDONLY);
	if (s->parse.fd == -1 )
		return (-1);
	while (get_next_line(s->parse.fd, &s->parse.line))
		if (treat_line(s) == -1)
		{
			printf("\"treat_line\" return = [-1]\n");
			return (-1);
		}
	make_map(s);
	close(s->parse.fd);
	return 0;
}
