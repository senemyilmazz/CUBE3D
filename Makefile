
SRCS =	./inc/get_next_line/get_next_line_utils.c ./inc/get_next_line/get_next_line.c \
		./src/cub3D.c ./src/utils/utils.c ./src/utils/file_path_utils.c  ./src/utils/error_utils.c \
		./src/file_check/check_file.c  ./src/file_check/check_textures.c \
		./src/file_check/check_map.c ./src/file_check/check_map_utils.c  ./src/file_check/check_map_is_valid_utils.c\

LIBFT = ./inc/libft/libft.a

MLX = ./inc/mlx/libmlx.a

OBJS = $(SRCS:.c=.o)

NAME = cub3D

CC = @gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address


all:$(NAME)

$(MLX):
	make -C ./inc/mlx

$(LIBFT):
	@make -C ./inc/libft

$(NAME): $(MLX) $(OBJS)
	@clear
	@echo "Compailing please wait"
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLX) -o $(NAME)
	@clear
	@rm -rf $(OBJS)
	@echo "cub3D compailed. for usage './cub3D <map_name>'"

clean:
	@make -C ./inc/libft clean
	@make -C ./inc/mlx clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C ./inc/libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re