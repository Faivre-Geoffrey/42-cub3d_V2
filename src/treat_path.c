/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:47:35 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/23 17:34:17 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	treat_no_path(t_all *s)
{
	int		i;

	if (s->parse.treat_no_path == 1 || s->parse.in_map == 0)
		ft_quit(s, "Error\nParsing return an error with NO\n");
	s->parse.lastisline = 0;
	s->parse.treat_no_path = 1;
	i = 2;
	while (s->parse.line[i] == ' ')
		i++;
	s->parse.no_path = ft_strdup(&s->parse.line[i]);
	return (0);
}

int	treat_so_path(t_all *s)
{
	int		i;

	if (s->parse.treat_so_path == 1 || s->parse.in_map == 0)
		ft_quit(s, "Error\nParsing return an error with SO\n");
	s->parse.lastisline = 0;
	s->parse.treat_so_path = 1;
	i = 2;
	while (s->parse.line[i] == ' ')
		i++;
	s->parse.so_path = ft_strdup(&s->parse.line[i]);
	return (0);
}

int	treat_we_path(t_all *s)
{
	int		i;

	if (s->parse.treat_we_path == 1 || s->parse.in_map == 0)
		ft_quit(s, "Error\nParsing return an error with WE\n");
	s->parse.lastisline = 0;
	s->parse.treat_we_path = 1;
	i = 2;
	while (s->parse.line[i] == ' ')
		i++;
	s->parse.we_path = ft_strdup(&s->parse.line[i]);
	return (0);
}

int	treat_ea_path(t_all *s)
{
	int		i;

	if (s->parse.treat_ea_path == 1 || s->parse.in_map == 0)
		ft_quit(s, "Error\nParsing return an error with EA\n");
	s->parse.lastisline = 0;
	s->parse.treat_we_path = 1;
	i = 2;
	while (s->parse.line[i] == ' ')
		i++;
	s->parse.ea_path = ft_strdup(&s->parse.line[i]);
	return (0);
}
