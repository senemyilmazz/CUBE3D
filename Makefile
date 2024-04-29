
SRCS =	./inc/get_next_line/get_next_line_utils.c ./inc/get_next_line/get_next_line.c \
		./src/cub3D.c ./src/utils/utils.c ./src/utils/file_path_utils.c  ./src/utils/error_utils.c \
		./src/file_check/check_file.c  ./src/file_check/check_textures.c \
		./src/file_check/check_map.c ./src/file_check/check_map_utils.c  ./src/file_check/check_map_is_valid_utils.c\

LIBFT = ./inc/libft/libft.a

MLX = ./mlx/libmlx.a

OBJS = $(SRCS:.c=.o)

NAME = cub3D

CC = @gcc

CFLAGS = -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit


all:$(NAME)

$(LIBFT):
	@make -C ./inc/libft

$(MLX):
	make -C ./mlx

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@clear
	@echo "Compailing please wait"
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLX) -o $(NAME)
	@clear
	@rm -rf $(OBJS)
	@echo "cub3D compailed. for usage './cub3D <map_name>'"

clean:
	@make -C ./inc/libft clean
	@make -C ./mlx clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C ./inc/libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re