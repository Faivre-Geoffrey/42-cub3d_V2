/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:43:13 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/21 17:43:33 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	det_egal_src(unsigned char *dest_c, unsigned char *src_c, size_t n)
{
	while (n > 0)
	{
		dest_c[n - 1] = src_c[n - 1];
		n--;
	}
}

void	det_egal_src_2(unsigned char *dest_c, unsigned char *src_c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest_c[i] = src_c[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_c;
	unsigned char	*src_c;

	dest_c = (unsigned char *)dest;
	src_c = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
		det_egal_src(dest_c, src_c, n);
	else
		det_egal_src_2(dest_c, src_c, n);
	return (dest_c);
}
