/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 09:09:27 by gefaivre          #+#    #+#             */
/*   Updated: 2020/12/07 08:03:51 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	size_t		i;
	char		*d_c;
	char		*s_c;

	i = 0;
	d_c = (char *)dest;
	s_c = (char *)src;
	while (i < size)
	{
		d_c[i] = s_c[i];
		if (d_c[i] == (char)c)
		{
			return (d_c + i + 1);
		}
		i++;
	}
	return (NULL);
}
