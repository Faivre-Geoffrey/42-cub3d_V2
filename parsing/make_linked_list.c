/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:15:46 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/09 12:08:06 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		make_linked_list(t_all *s)
{
	t_list *node;

	node = ft_lstnew(s->parse.line);
    ft_lstadd_back(&s->list, node);

	return (0);
}
