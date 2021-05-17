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




SRC =	raycasting.c \
		raycasting_2.c \
		utils.c \
		main.c \
		parsing.c \
		treat_path.c \
		treat_rgb.c \
		make_linked_list.c \
		make_map.c \
		check_parsing.c \
		print_map.c \
		move_and_dir.c \
		quit.c \
		save.c
		

NAME = cub3D

MLX_DIR = minilibx_linux
MLX = libmlx.a 
CC = clang

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = includes

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DPD = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.d))

.c.o:
	${CC} ${CFLAGS} -c$< -o ${<:.c=.o}


all:
	@$(MAKE) -j $(NAME)


$(NAME): $(OBJ) ft
		${CC} $(CFLAGS) -g -o $(NAME) $(OBJ) libft/libft.a -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext
		@echo $(NAME) : Created !

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | .gitignore
		@mkdir -p $(OBJ_DIR)
		${CC} $(CFLAGS) -I $(INC_DIR) -I $(MLX_DIR) -c $< -o $@

ft :
		make -C libft

.gitignore:
		@echo $(NAME) > .gitignore

clean:
	@$(MAKE) -C libft clean 
	@rm -rf $(OBJ_DIR)
	@echo "obj deleted"

fclean:	clean
	@$(MAKE) -C libft fclean 
	@rm -rf $(NAME)
	@echo "[$(NAME)]: deleted"

re: fclean all

.PHONY: all, clean, fclean, re

-include $(DPD)
