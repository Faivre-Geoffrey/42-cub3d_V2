/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:46:48 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/09 09:52:38 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int		treat_RGB(t_all *s)
{

	int tab[3];
	int i;

	i = 0;
	while (!(ft_isdigit(s->parse.line[i])))
		i++;
	tab[0] = ft_atoi(&s->parse.line[i]);
	while (ft_isdigit(s->parse.line[i]))
		i++;
	while (!(ft_isdigit(s->parse.line[i])))
		i++;
	tab[1] = ft_atoi(&s->parse.line[i]);
	while (ft_isdigit(s->parse.line[i]))
		i++;
	while (!(ft_isdigit(s->parse.line[i])))
		i++;
	tab[2] = ft_atoi(&s->parse.line[i]);

	return (rgbtohex(tab));

}
