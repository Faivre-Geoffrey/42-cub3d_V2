/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:15:46 by gefaivre          #+#    #+#             */
/*   Updated: 2021/05/10 12:53:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		make_linked_list(t_all *s)
{
	t_list *node;

	node = ft_lstnew(ft_strdup(s->parse.line));
    ft_lstadd_back(&s->list, node);

	return (0);
}
