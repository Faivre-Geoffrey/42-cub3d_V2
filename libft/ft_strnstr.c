/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 08:21:10 by gefaivre          #+#    #+#             */
/*   Updated: 2020/12/07 08:04:06 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *chrc, size_t n)
{
	size_t i;
	size_t j;

	if (*chrc == '\0')
		return ((char*)src);
	i = 0;
	while (src[i] && i < n)
	{
		j = 0;
		while (src[i + j] == chrc[j] && (i + j) < n)
		{
			j++;
			if (chrc[j] == '\0')
				return ((char*)src + i);
		}
		i++;
	}
	return (NULL);
}
