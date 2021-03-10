/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:43:19 by gefaivre          #+#    #+#             */
/*   Updated: 2020/12/15 13:26:58 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char *dst_c;
	char *src_c;

	dst_c = (char *)dst;
	src_c = (char *)src;
	if (dst == src)
		return (dst);
	if (src_c < dst_c)
	{
		while (len--)
			*(dst_c + len) = *(src_c + len);
		return (dst);
	}
	while (len--)
		*dst_c++ = *src_c++;
	return (dst);
}

char		*join(char const *s1, char const *s2)
{
	size_t	stot_len;
	char	*rtn_str;

	if (!s1 && !s2)
		return (0);
	stot_len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	rtn_str = malloc(sizeof(char) * stot_len);
	if (!rtn_str)
		return (0);
	ft_memmove(rtn_str, s1, ft_strlen((char *)s1));
	ft_memmove(rtn_str + ft_strlen((char *)s1), s2, ft_strlen((char *)s2));
	rtn_str[stot_len - 1] = '\0';
	free((char *)s1);
	return (rtn_str);
}

int			has_return(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
