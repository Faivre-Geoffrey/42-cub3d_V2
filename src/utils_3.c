/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:32:48 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/09 16:35:29 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	printback(t_all *s)
{
	printceiling(s);
	printfloor(s);
}

int	namecheck(char *arg, char *ext)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (arg[i] != '\0')
		i++;
	size = ft_strlen(ext);
	while (arg[i] != '.' && i < 0 && size < 0)
	{
		if (arg[i] != ext[size])
			return (-1);
		if (arg[i] == '.' && size != 0)
			return (-1);
		size--;
		i--;
	}
	return (1);
}
