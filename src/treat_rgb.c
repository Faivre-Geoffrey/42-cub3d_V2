/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:46:48 by gefaivre          #+#    #+#             */
/*   Updated: 2022/03/08 10:42:01 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	rgbtohex(int *tab)
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

void	increment_space(t_all *s, int *i)
{
	while (s->parse.line[*i] && s->parse.line[*i] == ' ')
		(*i)++;
}

int	parse_one_number(t_all *s, int *i, int nb)
{
	int	ret;

	increment_space(s, i);
	if (s->parse.line[*i] && ft_isdigit(s->parse.line[*i])
		&& my_atoi(&s->parse.line[*i]) > 0 && my_atoi(&s->parse.line[*i]) < 256)
		ret = my_atoi(&s->parse.line[*i]);
	else
		ft_quit(s, "Error\nOnly digit betwen 0 and 255 for RGB colors\n");
	while (s->parse.line[*i] && ft_isdigit(s->parse.line[*i]))
		(*i)++;
	increment_space(s, i);
	if (nb != 3)
	{
		if (s->parse.line[*i] != ',')
			ft_quit(s, "Error\nMust have ',' between RGB value\n");
		(*i)++;
	}
	else
	{
		increment_space(s, i);
		if (s->parse.line[*i] != '\0')
			ft_quit(s, "Error\nOnly three value for RGB colors\n");
	}
	return (ret);
}

void	make_hex(t_all *s, char x)
{
	int	tab[3];
	int	i;

	i = 1;
	tab[0] = parse_one_number(s, &i, 1);
	tab[1] = parse_one_number(s, &i, 2);
	tab[2] = parse_one_number(s, &i, 3);
	if (x == 'F')
		s->parse.rgb_f = rgbtohex(tab);
	else if (x == 'C')
		s->parse.rgb_c = rgbtohex(tab);
}

void	parse_rgb(t_all *s)
{
	if (ft_strncmp(s->parse.line, "F ", 2) == 0)
	{	
		if (s->parse.treat_rgb_f == 1 || s->parse.in_map == 0)
			ft_quit(s, "Error\nParsing return an error with F description\n");
		s->parse.lastisline = 0;
		s->parse.treat_rgb_f = 1;
		make_hex(s, 'F');
	}
	else if (ft_strncmp(s->parse.line, "C ", 2) == 0)
	{
		if (s->parse.treat_rgb_c == 1 || s->parse.in_map == 0)
			ft_quit(s, "Error\nParsing return an error with C description\n");
		s->parse.lastisline = 0;
		s->parse.treat_rgb_c = 1;
		make_hex(s, 'C');
	}
}
