/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:43:13 by gefaivre          #+#    #+#             */
/*   Updated: 2020/12/07 08:03:54 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_c;
	unsigned char	*src_c;

	dest_c = (unsigned char *)dest;
	src_c = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	i = 0;
	if (src < dest)
		while (n > 0)
		{
			dest_c[n - 1] = src_c[n - 1];
			n--;
		}
	else
		while (i < n)
		{
			dest_c[i] = src_c[i];
			i++;
		}
	return (dest_c);
}
