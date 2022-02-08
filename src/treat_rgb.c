/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:46:48 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/08 19:03:20 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		rgbtohex(int *tab)
{
	t_rgb	rgb;
	int		hex;

	rgb.r = tab[0];
	rgb.b = tab[2];
	rgb.g = tab[1];
	rgb.a = 0;
	hex = *(int *)&rgb;
	return (hex);
}



void	treat_oui_rgb(t_all *s, char x)
{
	int tab[3];
	int i;

	i = 0;
	while ((!(ft_isdigit(s->parse.line[i])) && s->parse.line[i]))
		i++;

	if (atoi(&s->parse.line[i]) > 255  || !(ft_isdigit(s->parse.line[i])))
		ft_quit(s, "Error\nThree number with value betwen 0 and 255 for RGB colors\n");
	else
		tab[0] = atoi(&s->parse.line[i]);

	while (ft_isdigit(s->parse.line[i]) && s->parse.line[i])
		i++;
	if (!(s->parse.line[i] == ',') && s->parse.line[i])
		ft_quit(s, "Error\nMust have ',' between RGB value\n");
	while (!(ft_isdigit(s->parse.line[i]))&& s->parse.line[i])
		i++;
	if (atoi(&s->parse.line[i]) > 255  || !ft_isdigit(s->parse.line[i]))
		ft_quit(s, "Error\nThree number with value betwen 0 and 255 for RGB colors\n");
	else
		tab[1] = atoi(&s->parse.line[i]);
	while (ft_isdigit(s->parse.line[i])&& s->parse.line[i])
		i++;
	if (!(s->parse.line[i] == ',') && s->parse.line[i])
		ft_quit(s, "Error\nMust have ',' between RGB value\n");
	while (!(ft_isdigit(s->parse.line[i]))&& s->parse.line[i])
		i++;
	if (atoi(&s->parse.line[i]) > 255  || !ft_isdigit(s->parse.line[i]))
		ft_quit(s ,"Error\nThree number with value betwen 0 and 255 for RGB colors\n");
	else
		tab[2] = atoi(&s->parse.line[i]);
	while ((!(ft_isdigit(s->parse.line[i])) && s->parse.line[i]) )
	{
		i++;
		if ((ft_isdigit(s->parse.line[i]) && s->parse.line[i]))
			ft_quit(s, "Error\nThree number only for RGB colors please\n");
	}
	if (x == 'F')
		s->parse.rgb_F = rgbtohex(tab);
	else if (x == 'C')
		s->parse.rgb_C = rgbtohex(tab);
}


void		treat_RGB(t_all *s)
{
	if (ft_strncmp(s->parse.line, "F ", 2) == 0)
	{	
		if (s->parse.treat_RGB_F == 1 || s->parse.in_map == 0)
			ft_quit(s, "Error\n parsing return an error with F description");
		s->parse.lastisline = 0;
		s->parse.treat_RGB_F = 1;
		treat_oui_rgb(s, 'F');
	}
	else if (ft_strncmp(s->parse.line, "C ", 2) == 0)
	{
		if (s->parse.treat_RGB_C == 1 || s->parse.in_map == 0)
			ft_quit(s, "Error\n parsing return an error with C description");
		s->parse.lastisline = 0;
		s->parse.treat_RGB_C = 1;
		treat_oui_rgb(s, 'C');	
	}
}
