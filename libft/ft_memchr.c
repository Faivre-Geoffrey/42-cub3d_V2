/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:19:03 by gefaivre          #+#    #+#             */
/*   Updated: 2020/12/07 08:03:52 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src_c;

	i = 0;
	src_c = (unsigned char *)src;
	while (i < n)
	{
		if (src_c[i] == (unsigned char)c)
			return (src_c + i);
		i++;
	}
	return (NULL);
}
