/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:28:08 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/11 13:59:58 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	printmap(t_all *s)
{
	s->axe.x = 0;
	s->axe.x_count = 0;
	/* s->map.size.x -= 4;
	s->map.size.y -= 4; */
	s->parse.diviseur = /* ft_intmin(s->parse.width_window_size, s->parse.height_window_size) / ft_intmax(s->map.size.x, s->map.size.y); */
						s->parse.width_window_size / s->map.size.x;

	/* printf("diviseur = %i\n", diviseur);
	printf("s_parsing->m_height = %i\n", s_parsing->m_height);
	printf("s_parsing->m_width = %i\n", s_parsing->m_width);
	printf("s_parsing->x_render_size = %i\n", s_parsing->x_render_size);
	printf("s_parsing->y_render_size = %i\n", s_parsing->y_render_size);
	printf("s_parsing->m_width *  diviseur= %i\n", s_parsing->m_width *  diviseur); */

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
	printf("NO SEG FAULT");
}
