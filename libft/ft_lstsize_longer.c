/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_longer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:22:25 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/09 12:47:37 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize_longer(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		if ((int)ft_strlen(lst->content) > i)
			i = ft_strlen(lst->content);
		lst = lst->next;
	}
	return (i);
}
