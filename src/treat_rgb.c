/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:46:48 by gefaivre          #+#    #+#             */
/*   Updated: 2021/05/11 13:07:47 by user42           ###   ########.fr       */
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


int		treat_RGB(t_all *s)
{
	int tab[3];
	int i;

	i = 0;
	while ((!(ft_isdigit(s->parse.line[i])) && s->parse.line[i]))
		i++;

	if (atoi(&s->parse.line[i]) > 255  || !(ft_isdigit(s->parse.line[i])))
	{
		printf("Three number with value betwen 0 and 255 for RGB colors\n");
		return -1;
	}
	else
		tab[0] = atoi(&s->parse.line[i]);

	while (ft_isdigit(s->parse.line[i]) && s->parse.line[i])
		i++;
	if (!(s->parse.line[i] == ',') && s->parse.line[i])
		return (-1);
	while (!(ft_isdigit(s->parse.line[i]))&& s->parse.line[i])
		i++;

	if (atoi(&s->parse.line[i]) > 255  || !ft_isdigit(s->parse.line[i]))
	{
		printf("Three number with value betwen 0 and 255 for RGB colors\n");
		return -1;
	}
	else
		tab[1] = atoi(&s->parse.line[i]);

	while (ft_isdigit(s->parse.line[i])&& s->parse.line[i])
		i++;
	if (!(s->parse.line[i] == ',') && s->parse.line[i])
		return (-1);
	while (!(ft_isdigit(s->parse.line[i]))&& s->parse.line[i])
		i++;

	if (atoi(&s->parse.line[i]) > 255  || !ft_isdigit(s->parse.line[i]))
	{
		printf("Three number with value betwen 0 and 255 for RGB colors\n");
		return -1;
	}
	else
		tab[2] = atoi(&s->parse.line[i]);
	while ((!(ft_isdigit(s->parse.line[i])) && s->parse.line[i]) )
	{
		i++;
		if ((ft_isdigit(s->parse.line[i]) && s->parse.line[i]))
		{
			printf("Three number only for RGB colors please\n");
			return (-1);
		}
	}
	return (rgbtohex(tab));
}

