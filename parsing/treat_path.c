/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:47:35 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/09 09:52:51 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		treat_NO_path(t_all *s)
{
	int		i;

	i = 2;
	while (s->parse.line[i] == ' ')
		i++;
	s->parse.NO_path = ft_strdup(&s->parse.line[i]);
	return 0;
}

int		treat_SO_path(t_all *s)
{
	int		i;

	i = 2;
	while (s->parse.line[i] == ' ')
		i++;
	s->parse.SO_path = ft_strdup(&s->parse.line[i]);
	return 0;
}

int		treat_WE_path(t_all *s)
{
	int		i;

	i = 2;
	while (s->parse.line[i] == ' ')
		i++;
	s->parse.WE_path = ft_strdup(&s->parse.line[i]);
	return 0;
}

int		treat_EA_path(t_all *s)
{
	int		i;

	i = 2;
	while (s->parse.line[i] == ' ')
		i++;
	s->parse.EA_path = ft_strdup(&s->parse.line[i]);
	return 0;
}

int		treat_S_path(t_all *s)
{
	int		i;

	i = 1;
	while (s->parse.line[i] == ' ')
		i++;
	s->parse.S_path = ft_strdup(&s->parse.line[i]);
	return 0;
}
