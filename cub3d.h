/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:59:54 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/10 16:21:23 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "GNL/get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mlx.h>

typedef struct		s_rgb {
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_rgb;

typedef struct		s_axe {
	int				x;
	int				y;
}					t_axe;

typedef	struct		s_parse
{
	int				fd;
	char			*line;
	int				height_window_size;
	int				width_window_size;
	int				rgb_F;
	int				rgb_C;
	char			*NO_path;
	char			*SO_path;
	char			*WE_path;
	char			*EA_path;
	char			*S_path;
}					t_parse;

typedef	struct		s_map
{
	char			**map;
	t_axe			size;

}					t_map;

typedef	struct		s_start
{
	t_axe			pos;
	char			NSEW;
	int				count;

}					t_start;

typedef struct		s_data {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	void			*mlx_win;
}					t_data;

typedef	struct		s_all
{
	t_data 			mlx;
	t_parse			parse;
	t_map 			map;
	t_axe			axe;
	t_list			*list;
	t_start			start;

}					t_all;

int		parsing(t_all *s);

int		treat_NO_path(t_all *s);
int		treat_SO_path(t_all *s);
int		treat_WE_path(t_all *s);
int		treat_EA_path(t_all *s);
int		treat_S_path(t_all *s);

int		rgbtohex(int *tab);
int		treat_RGB(t_all *s);

int		make_linked_list(t_all *s);

int		make_map(t_all *s);

int		check_parsing(t_all *s);






void	print_map(t_all *s);
void	print_list(t_all *s);
int		is_start_pos(char c);
void		 pixel_put(t_all *s, int x, int y, int color);

#endif
