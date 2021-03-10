/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:48:32 by gefaivre          #+#    #+#             */
/*   Updated: 2020/12/07 08:03:48 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_positivator(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

static void	ft_strrev(char *str)
{
	size_t	i;
	size_t	length;
	char	tmp;

	i = 0;
	length = ft_strlen(str);
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		neg;
	size_t	i;

	if (!(str = ft_calloc(12, sizeof(*str))))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	neg = (n < 0);
	i = 0;
	while (n != 0)
	{
		str[i++] = '0' + ft_positivator(n % 10);
		n = (n / 10);
	}
	if (neg)
		str[i] = '-';
	ft_strrev(str);
	return (str);
}
