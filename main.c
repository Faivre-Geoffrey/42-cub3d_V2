/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 08:07:02 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/10 12:41:02 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_all *s)
{
	s->list = NULL;
}

int		main()
{
	t_all s;

	init(&s);
	parsing(&s);
	check_parsing(&s);


	printf("%s\n",s.parse.EA_path);
	printf("%s\n",s.parse.NO_path);
	printf("%s\n",s.parse.S_path);
	printf("%s\n",s.parse.SO_path);
	printf("%s\n",s.parse.WE_path);
	printf("%d\n",s.parse.rgb_F);
	printf("%d\n",s.parse.rgb_C);
	printf("%d\n",s.map.size.x);
	printf("%d\n",s.map.size.y);



	return (0);
}
