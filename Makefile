
SRCS =	./get_next_line/get_next_line_utils.c ./get_next_line/get_next_line.c \
		cub3D.c utils.c file_check.c read_file.c

LIBFT = ./libft/libft.a

OBJS = $(SRCS:.c=.o)

NAME = cub3D

CC = @gcc

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address


all:$(LIBFT) $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJS)
	@clear
	@echo "Compailing please wait"
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@clear
	@rm -rf $(OBJS)
	@echo "cub3D compailed. for usage './cub3D <map_name>'"

clean:
	@make -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re