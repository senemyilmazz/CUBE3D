
SRCS =	./inc/get_next_line/get_next_line_utils.c ./inc/get_next_line/get_next_line.c \
		./src/cub3D.c ./src/utils/utils.c ./src/utils/file_path_utils.c  ./src/utils/error_utils.c \
		./src/file_check/check_file.c  ./src/file_check/check_textures.c ./src/file_check/set_info_to_data.c\
		./src/file_check/check_map.c ./src/file_check/check_map_utils.c  ./src/file_check/check_map_is_valid_utils.c\
		./src/game/game_init.c ./src/game/draw_content.c ./src/game/calculate.c

LIBFT = ./inc/libft/libft.a

MLX = ./mlx/libmlx.a

OBJS = $(SRCS:.c=.o)

NAME = cub3D

CC = @gcc

CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address 
MFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit


all:$(NAME)

$(LIBFT):
	@make -C ./inc/libft

$(MLX):
	make -C ./mlx

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(MFLAGS) $(SRCS) $(MLX) $(LIBFT) -o $(NAME)

clean:
	@make clean -C ./inc/libft
	@make clean -C ./mlx
	@rm -rf $(OBJS)

fclean: clean
	@make -C ./inc/libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re