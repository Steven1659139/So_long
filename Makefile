NAME = so_long

SRCS = so_long.c my_mlx_pixel_put.c test_form.c parsing.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

BRANCH ?= $(shell bash -c 'read -p "Branch: " branch; echo $$branch')
COMMIT ?= $(shell bash -c 'read -p "Commit: " commit; echo $$commit')
ANSWER ?= $(shell bash -c 'read -p "Is OK ? " answer; echo $$answer')

%.o: %.c
	gcc $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	gcc $(CFLAGS) $(OBJS) ./Libft/libft.a $(MLXFLAGS) -o $(NAME)

clean:
	@$(MAKE) -C  Libft fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

add:
	git add *.c *.h Makefile *.xpm *.ber
	git status

stat: add
	git branch

com: stat
		git commit -m $(COMMIT)
p: com
	git push origin $(BRANCH)