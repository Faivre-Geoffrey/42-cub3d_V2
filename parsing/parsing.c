/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 07:16:17 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/09 12:10:54 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		treat_window_size(t_all *s)
{
	int		i;
	int		j;

	i = 0;
	while (!(ft_isdigit(s->parse.line[i])))
		i++;
	j = 0;
	if (ft_isdigit(s->parse.line[i]))
		s->parse.width_window_size = ft_atoi(&s->parse.line[i]);
	while (ft_isdigit(s->parse.line[i]))
		i++;
	while (!(ft_isdigit(s->parse.line[i])))
		i++;
	if (ft_isdigit(s->parse.line[i]))
		s->parse.height_window_size = ft_atoi(&s->parse.line[i]);
	return 0;
}

int	is_line_at_map(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W' && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		treat_line(t_all *s)
{
	if (s->parse.line[0] == 'R')
		treat_window_size(s);
	if (s->parse.line[0] == 'N' && s->parse.line[1] == 'O')
		treat_NO_path(s);
	if (s->parse.line[0] == 'S' && s->parse.line[1] == 'O')
		treat_SO_path(s);
	if (s->parse.line[0] == 'W' && s->parse.line[1] == 'E')
		treat_WE_path(s);
	if (s->parse.line[0] == 'E' && s->parse.line[1] == 'A')
		treat_EA_path(s);
	if (s->parse.line[0] == 'S')
		treat_S_path(s);
	if (s->parse.line[0] == 'F')
		s->parse.rgb_F = treat_RGB(s);
	if (s->parse.line[0] == 'C')
		s->parse.rgb_C = treat_RGB(s);
	if (is_line_at_map(s->parse.line))
		make_linked_list(s);
	return 0;
}

int		parsing(t_all *s)
{
	s->parse.line = NULL;
	s->parse.fd = open("cub3d.cub", O_RDONLY);
	if (s->parse.fd == -1 )
		return (-1);
	while (get_next_line(s->parse.fd, &s->parse.line))
		treat_line(s);
	make_map(s);
	close(s->parse.fd);
	return 0;
}
