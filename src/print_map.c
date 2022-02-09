/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:28:08 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/09 15:36:17 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	printmap(t_all *s)
{
	s->axe.x = 0;
	s->axe.x_count = 0;
	s->parse.diviseur = W_WINDOW / s->map.size.x;
	while (s->axe.x_count < s->map.size.x)
	{
		s->axe.y = 0;
		s->axe.y_count = 0;
		while (s->axe.y_count < s->map.size.y)
		{
			if (s->map.map[s->axe.y_count + 2][s->axe.x_count + 2] == '0')
				square_put(s, s->parse.diviseur, 0X00FFFFFF);
			else if (s->map.map[s->axe.y_count + 2][s->axe.x_count + 2] == ' ')
				square_put(s, s->parse.diviseur, 0x00650000);
			else if (s->map.map[s->axe.y_count + 2][s->axe.x_count + 2] == 'N')
				square_put(s, s->parse.diviseur, 0x00FF0000);
			else
				square_put(s, s->parse.diviseur, 0x0066D0E8);
			s->axe.y = s->axe.y + s->parse.diviseur;
			s->axe.y_count++;
		}
		s->axe.x = s->axe.x + s->parse.diviseur;
		s->axe.x_count++;
	}
}
