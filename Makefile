NAME = so_long

SRCS = so_long.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	gcc $(CFLAGS) $(OBJS) ./Libft/libft.a -o $(NAME)

clean:
	@$(MAKE) -C  Libft fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

add:
	git add *.c *.h Makefile
	git status
push:
	git push origin master