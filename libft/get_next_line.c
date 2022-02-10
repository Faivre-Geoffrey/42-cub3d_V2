/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:31:03 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/10 19:57:35 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_new_save(char *save)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	rtn = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1));
	if (!rtn)
		return (0);
	i++;
	while (save[i])
		rtn[j++] = save[i++];
	rtn[j] = '\0';
	free(save);
	return (rtn);
}

char	*get_line(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	rtn = malloc(sizeof(char) * (i + 1));
	if (!rtn)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int	free_the_buff(char *buff)
{
	free(buff);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char		*save;
	int				read_value;
	char			*buff;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	read_value = 1;
	while (!has_return(save) && read_value != 0)
	{
		read_value = read(fd, buff, BUFFER_SIZE);
		if (read_value == -1)
			return (free_the_buff(buff));
		buff[read_value] = 0;
		save = join(save, buff);
	}
	free(buff);
	*line = get_line(save);
	save = get_new_save(save);
	if (read_value == 0)
		return (0);
	return (1);
}
