/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:59:54 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/09 14:29:15 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

#define TEXHEIGHT 64
#define Vdir 0.02
#define Vspeed 0.05


typedef struct		s_rgb {
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_rgb;

typedef struct		s_axe {
	int				x;
	int				y;
	int				x_count;
	int				y_count;
}					t_axe;

typedef struct		s_axe_f {
	float			x;
	float			y;
	float			x_count;
	float			y_count;
	double			a;
}					t_axe_f;

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
	int				diviseur;
	char			*map_path;
	int				lastisline;
	int				in_map;
	int				spaceinmap;
	int				treat_window_size;
	int				treat_no_path;
	int				treat_so_path;
	int				treat_we_path;
	int				treat_ea_path;
	int				treat_S_path;
	int				treat_RGB_F;
	int				treat_RGB_C;
	int				numsprite;
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
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	void			*mlx_win;
}					t_data;

typedef struct		s_boy{
	t_axe_f			pos;
	t_axe_f			dir;
	t_axe_f			plane;
	int 			forward;
	int				backward;
	int				leftward;
	int				rightward;
	int				dirright;
	int				dirleft;

}					t_boy;

typedef struct		s_rc{
	float			cameraX;
	float			rayDirX;
	float			rayDirY;
	int				mapX;
	int				mapY;
	float			sideDistX;
	float			sideDistY;
	float			deltaDistX;
	float			deltaDistY;
	float			perpWallDist;
	int 			stepX;
	int 			stepY;
	int 			hit;
	int 			side;
	int 			lineHeight;
	int 			drawStart;
	int 			drawEnd;
	int 			texNum;
	float			wallX;
	int 			texX;
	int 			texY;
	float			step;
	float			texPos;
}					t_rc;

typedef struct	s_cp
{
	t_data		mlx;
	t_parse		parse;
}				t_cp;

typedef	struct		s_all
{
	t_data 			mlx;
	t_data			texture[5];
	t_parse			parse;
	t_map 			map;
	t_axe			axe;
	t_list			*list;
	t_start			start;
	t_boy			boy;
	t_rc			rc;
	t_cp			cp;
}					t_all;

void	ft_quit(t_all *s, char* str);
void	save(t_all *s, char *str);


int		set_move(t_all *s);

void		parsing(t_all *s);

int		treat_no_path(t_all *s);
int		treat_so_path(t_all *s);
int		treat_we_path(t_all *s);
int		treat_ea_path(t_all *s);
int		treat_S_path(t_all *s);

int		rgbtohex(int *tab);
void		parse_rgb(t_all *s);

int		make_linked_map(t_all *s);

int		make_map(t_all *s);

void		check_parsing(t_all *s);

void	forward(t_all *s);
void	backward(t_all *s);
void	leftward(t_all *s);
void	rightward(t_all *s);
void	dirleft(t_all *s);
void	dirright(t_all *s);

void	printboy(t_all *s);


void	raycasting(t_all *s);
void	drawline_tex(t_all *s);
void	set_texture(t_all *s);
void	rc_hit(t_all *s);
void	rc_step_and_dist(t_all *s);
void	set_rc_var(t_all *s);


void	print_map(t_all *s);
void	print_list(t_all *s);
int		is_start_pos(char c);
void	pixel_put(t_all *s, int x, int y, int color);
void	square_put(t_all *s, int size, int color);

void	printmap(t_all *s);
void	printback(t_all *s);
void	drawline(t_all *s);


int		ft_namecheck(char *arg, char *ext);
void fuck_up_fonction(void *i);

int		ismovable(char c);

#endif
