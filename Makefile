_END=\x1b[0m
_BOLD=\x1b[1m
_UNDER=\x1b[4m
_REV=\x1b[7m

# Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m

# Inverted, i.e. colored backgrounds
_IGREY=\x1b[40m
_IRED=\x1b[41m
_IGREEN=\x1b[42m
_IYELLOW=\x1b[43m
_IBLUE=\x1b[44m
_IPURPLE=\x1b[45m
_ICYAN=\x1b[46m
_IWHITE=\x1b[47m


NAME = cub3D

MLX = -lmlx -lm -framework OpenGL -framework AppKit
#MLX = -I /usr/include -g -L /usr/lib -lX11 -lmlx -lXext -lm -fsanitize=address

CC = gcc

RM = rm -rf

CFLAGS = #-Werror -Wall -Wextra

SRCS =	GNL/get_next_line.c \
		GNL/get_next_line_utils.c \
		parsing/parsing.c \
		parsing/treat_path.c \
		parsing/treat_rgb.c \
		parsing/make_linked_list.c \
		parsing/make_map.c \
		parsing/check_parsing.c \
		map/print_map.c \
		move/move.c \
		move/move_dir.c \
		move/raycasting.c \
		move/raycasting_2.c \
			utils.c \
			main.c


OBJS = $(SRCS:.c=.o)




all: $(OBJS)
	@echo "\n"
	@echo "\t\t $(_IWHITE)$(_BLUE)Make cub3D with remake library$(_END)"
	@echo "\n"
	@echo "$(_BLUE)[Remove last version...]$(_END)"
	@rm -rf Cub3D
	@echo "$(_GREEN)[OK 1/3]$(_END)"
	@echo "$(_BLUE)[Libft compilation...]$(_END)"
	@echo "$(_PURPLE)"
	@$(MAKE) -C ./libft
	@echo "$(_END)"
	@echo "$(_GREEN)[OK 2/3]$(_END)"
	@echo "$(_BLUE)[Cub3D compilation...]$(_END)"
	@$(CC) $(SRCS) -I./includes -I./usr/include $(CFLAGS) $(MLX) ./libft/libft.a -o $(NAME)
	@echo "$(_GREEN)[OK 3/3]$(_END)"
	@echo "$(_GREY)$(_IGREEN)\t\t[Done !]$(_END)"

nolib: $(OBJS)
	@echo "\n"
	@echo "\t\t $(_IWHITE)$(_BLUE)Make cub3D without remake library$(_END)"
	@echo "\n"
	@echo "$(_GREEN)[Remove last version...]$(_END)"
	@rm -rf Cub3D
	@echo "$(_GREEN)[Cub3D compilation...]$(_END)"
	@$(CC) $(SRCS) -I./includes -I./usr/include $(CFLAGS) $(MLX) ./libft/libft.a -o $(NAME)
	@echo "$(_GREEN)[Done !]$(_END)"

clean :
	@echo "\n"
	@echo "\t\t $(_IWHITE)$(_BLUE)Clean all .o$(_END)"
	@echo "\n"
	@$(RM) $(OBJS)
	@$(MAKE) clean -C ./libft

fclean : clean
	@$(RM) $(NAME)
	@$(RM) cub3d.bmp

re : fclean all

