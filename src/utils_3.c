/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:32:48 by gefaivre          #+#    #+#             */
/*   Updated: 2022/03/08 14:30:20 by gefaivre         ###   ########.fr       */
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

int	my_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	if (str[i] == '-')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < 9)
		res = (res * 10) + (str[i++] - '0');
	return (res * neg);
}
