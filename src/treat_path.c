/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:47:35 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/08 18:43:22 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		treat_NO_path(t_all *s)
{
	int		i;

	if (s->parse.treat_NO_path == 1 || s->parse.in_map == 0)
		ft_quit(s, "Error\n parsing return an error with NO");
	s->parse.lastisline = 0;
	s->parse.treat_NO_path = 1;
	i = 2;
	while (s->parse.line[i] == ' ')
		i++;
	s->parse.NO_path = ft_strdup(&s->parse.line[i]);
	return 0;
}

int		treat_SO_path(t_all *s)
{
	int		i;

	if (s->parse.treat_SO_path == 1 || s->parse.in_map == 0)
			ft_quit(s, "Error\n parsing return an error with SO");
	s->parse.lastisline = 0;
	s->parse.treat_SO_path = 1;
	i = 2;
	while (s->parse.line[i] == ' ')
		i++;
	s->parse.SO_path = ft_strdup(&s->parse.line[i]);
	return 0;
}

int		treat_WE_path(t_all *s)
{
	int		i;

	if (s->parse.treat_WE_path == 1 || s->parse.in_map == 0)
		ft_quit(s, "Error\n parsing return an error with WE");
	s->parse.lastisline = 0;
	s->parse.treat_WE_path = 1;
	i = 2;
	while (s->parse.line[i] == ' ')
		i++;
	s->parse.WE_path = ft_strdup(&s->parse.line[i]);
	return 0;
}

int		treat_EA_path(t_all *s)
{
	int		i;

	if (s->parse.treat_EA_path == 1 || s->parse.in_map == 0)
		ft_quit(s, "Error\n parsing return an error with EA");
	s->parse.lastisline = 0;
	s->parse.treat_WE_path = 1;
	i = 2;
	while (s->parse.line[i] == ' ')
		i++;
	s->parse.EA_path = ft_strdup(&s->parse.line[i]);
	return 0;
}