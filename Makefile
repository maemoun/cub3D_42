NAME	:= cub3D
CC		:= cc

CFLAGS	:= -Wall -Wextra -Werror -fsanitize=address

SRC		:= cub3d.c \
			./parsing/parsing.c \
			./parsing/check_file_name.c \
			./parsing/print_error.c \
			./parsing/read_fd.c \
			./parsing/get_next_line/get_next_line_utils.c \
			./parsing/get_next_line/get_next_line.c \
			./parsing/split.c \
			./parsing/utils.c \
			./parsing/init_fd.c \
			./parsing/utils/ft_strtrim.c \
			./parsing/utils/ft_memset.c \
			./parsing/utils/ft_memcpy.c \


OBJ		:= $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $(NAME)

%.o: %.c	./parsing/cub3d.h
		$(CC) -c $< -o $@

clean:
		rm -rf $(OBJ)

fclean:	clean
		rm -rf $(NAME)

re:	fclean all