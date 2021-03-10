/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:47:43 by gefaivre          #+#    #+#             */
/*   Updated: 2020/12/07 08:04:00 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*str_c;

	i = 0;
	str_c = (char*)str;
	while (str_c[i])
	{
		if (str_c[i] == (char)c)
			return (str_c + i);
		i++;
	}
	if (str_c[i] == (char)c)
		return (str_c + i);
	return (NULL);
}
