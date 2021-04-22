_END=\033[0m
_BOLD=\033[1m
_UNDER=\033[4m
_REV=\033[7m

# Colors
_GREY=\033[30m
_RED=\033[31m
_GREEN=\033[32m
_YELLOW=\033[33m
_BLUE=\033[34m
_PURPLE=\033[35m
_CYAN=\033[36m
_WHITE=\033[37m

# Inverted, i.e. colored backgrounds
_IGREY=\033[40m
_IRED=\033[41m
_IGREEN=\033[42m
_IYELLOW=\033[43m
_IBLUE=\033[44m
_IPURPLE=\033[45m
_ICYAN=\033[46m
_IWHITE=\033[47m




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

MLX_DIR	= minilibx_linux

NAME = cub3D


MLX = -lm -lbsd -lmlx -LX11 -LXest

CC = gcc

RM = rm -rf

CFLAGS = -Werror -Wall -Wextra

HEADER = -I .


all: $(NAME)

$(NAME) : $(OBJS) ft mlx
	@echo "\n"
	@echo "\t\t $(_IWHITE)$(_BLUE)Make cub3D with remake library$(_END)"
	@echo "\n"
	@echo "$(_BLUE)[Remove last version...]$(_END)"
	@rm -rf Cub3D
	@echo "$(_GREEN)[OK 1/3]$(_END)"
	@echo "$(_BLUE)[Libft compilation...]$(_END)"
	@echo "$(_GREEN)[OK 2/3]$(_END)"
	@echo "$(_BLUE)[Cub3D compilation...]$(_END)"
	@$(CC) $(CFLAGS) $(HEADER) -L $(MLX_DIR) -o $(NAME)  $(SRCS) $(MLX)  ./minilibx_linux/libmlx_Linux.a
	@echo "$(_GREEN)[OK 3/3]$(_END)"
	@echo "$(_GREY)$(_IGREEN)\t\t[Done !]$(_END)"

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INC}

mlx:
	@echo "\033[34m-= Making mlx... =-"
	@make -C $(MLX_DIR)
	@echo "\033[34m-= mlx Done ! =-"

ft:
	@echo "\033[33m-= Making Libft... =-"
	@make -C libft
	@echo "\033[33m-= Libft Done ! =-"

nolib: $(OBJS)
	@echo "\n"
	@echo "\t\t $(_IWHITE)$(_BLUE)Make cub3D without remake library$(_END)"
	@echo "\n"
	@echo "$(_GREEN)[Remove last version...]$(_END)"
	@rm -rf Cub3D
	@echo "$(_GREEN)[Cub3D compilation...]$(_END)"
	@$(CC) $(SRCS) -I./includes -I./usr/include $(CFLAGS) $(MLX)  -o $(NAME)
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

