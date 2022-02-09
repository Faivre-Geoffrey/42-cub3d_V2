/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:47:35 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/09 14:14:30 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	treat_no_path(t_all *s)
{
	int		i;

	if (s->parse.treat_no_path == 1 || s->parse.in_map == 0)
		ft_quit(s, "Error\nParsing return an error with NO");
	s->parse.lastisline = 0;
	s->parse.treat_no_path = 1;
	i = 2;
	while (s->parse.line[i] == ' ')
		i++;
	s->parse.NO_path = ft_strdup(&s->parse.line[i]);
	return (0);
}

int	treat_so_path(t_all *s)
{
	int		i;

	if (s->parse.treat_so_path == 1 || s->parse.in_map == 0)
		ft_quit(s, "Error\nParsing return an error with SO");
	s->parse.lastisline = 0;
	s->parse.treat_so_path = 1;
	i = 2;
	while (s->parse.line[i] == ' ')
		i++;
	s->parse.SO_path = ft_strdup(&s->parse.line[i]);
	return (0);
}

int	treat_we_path(t_all *s)
{
	int		i;

	if (s->parse.treat_we_path == 1 || s->parse.in_map == 0)
		ft_quit(s, "Error\nParsing return an error with WE");
	s->parse.lastisline = 0;
	s->parse.treat_we_path = 1;
	i = 2;
	while (s->parse.line[i] == ' ')
		i++;
	s->parse.WE_path = ft_strdup(&s->parse.line[i]);
	return (0);
}

int	treat_ea_path(t_all *s)
{
	int		i;

	if (s->parse.treat_ea_path == 1 || s->parse.in_map == 0)
		ft_quit(s, "Error\nParsing return an error with EA");
	s->parse.lastisline = 0;
	s->parse.treat_we_path = 1;
	i = 2;
	while (s->parse.line[i] == ' ')
		i++;
	s->parse.EA_path = ft_strdup(&s->parse.line[i]);
	return (0);
}
