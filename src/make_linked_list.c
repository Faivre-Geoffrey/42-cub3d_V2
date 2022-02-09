/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:15:46 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/09 14:18:12 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		make_linked_map(t_all *s)
{
	t_list *node;

	if (s->parse.lastisline == 1 &&  s->parse.spaceinmap == 1)
			ft_quit(s,"Error\nDon't break the map in .cub\n");
		s->parse.in_map = 0;
		s->parse.lastisline = 1;

	node = ft_lstnew(ft_strdup(s->parse.line));
    ft_lstadd_back(&s->list, node);

	return (0);
}
