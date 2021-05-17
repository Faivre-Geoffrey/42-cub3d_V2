/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:29:46 by user42            #+#    #+#             */
/*   Updated: 2021/05/17 15:01:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
 
void	ft_quit(t_all *s, char* str)
{






	
	if (s->list)
		ft_lstclear(&s->list, free);
	int i = 0;
	if (s->map.map)
	{
		while (s->map.map[i] && i < s->map.size.y +4 )
		{
			free(s->map.map[i]);
			i++;
		}	
		free(s->map.map);
	}	
	if(s->parse.line)
		free(s->parse.line);
	if (s->spr.zbuffer)
		free(s->spr.zbuffer);
	if (s->spr.spriteDistance)
		free(s->spr.spriteDistance);
	if(s->spr.spriteOrder)
		free(s->spr.spriteOrder);
	if (s->mlx.img)
		mlx_destroy_image(s->mlx.mlx, s->mlx.img);
    printf("%s", str);
	exit(0);
}