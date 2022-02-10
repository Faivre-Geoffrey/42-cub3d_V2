/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 07:16:17 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/10 19:34:47 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_path(t_all *s, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
			ft_quit(s, "Error\nBad map_path name\n");
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u'
		&& str[i + 3] == 'b' && str[i + 4] == '\0')
	{
		s->parse.map_path = str;
		return ;
	}
	ft_quit(s, "Error\nBad map_path name\n");
}

int	my_atoi(const char *str)
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

int	is_line_at_map(char *str)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != 'N' && str[i] != 'S' && str[i] != 'E'
			&& str[i] != 'W' && str[i] != '0' && str[i] != '1')
			return (0);
		if (str[i] == '1' || str[i] == '0')
			x = 1;
		i++;
	}
	return (x);
}

void	treat_line(t_all *s)
{
	if (ft_strncmp(s->parse.line, "NO ", 3) == 0)
		treat_no_path(s);
	else if (ft_strncmp(s->parse.line, "SO ", 3) == 0)
		treat_so_path(s);
	else if (ft_strncmp(s->parse.line, "WE ", 3) == 0)
		treat_we_path(s);
	else if (ft_strncmp(s->parse.line, "EA ", 3) == 0)
		treat_ea_path(s);
	else if (ft_strncmp(s->parse.line, "F ", 2) == 0
		|| ft_strncmp(s->parse.line, "C ", 2) == 0)
		parse_rgb(s);
	else if (is_line_at_map(s->parse.line))
	{
		make_linked_map(s);
	}
	else if ((int)ft_strlen(s->parse.line) <= 1)
	{
		if (s->parse.in_map == 0)
			s->parse.spaceinmap = 1;
	}
	else
		ft_quit(s, "Error\nBad symbole in .cub");
}

void	parsing(t_all *s)
{
	s->parse.line = NULL;
	s->parse.fd = open(s->parse.map_path, __O_DIRECTORY);
	if (s->parse.fd != -1)
		ft_quit(s, "Error\nmap_path can't be a directory\n");
	s->parse.fd = open(s->parse.map_path, O_RDONLY);
	if (s->parse.fd == -1)
		ft_quit(s, "Error\nbad name .cub\n");
	while (get_next_line(s->parse.fd, &s->parse.line))
	{
		treat_line(s);
		free(s->parse.line);
	}
	make_map(s);
	close(s->parse.fd);
	return ;
}
