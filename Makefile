NAME = so_long

SRCS = so_long.c my_mlx_pixel_put.c test_form.c parsing.c image.c map.c

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
	gcc $(CFLAGS) $(OBJS) ./Libft/libft.a MinilibX/libmlx.a $(MLXFLAGS) -o $(NAME)

clean:
	@$(MAKE) -C  Libft fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

add:
	@$(MAKE) -C Libft add
	git add *.c *.h Makefile *.xpm *.ber
	git status

sub:
	git submodule update --init --recursive

stat: add
	git branch

com: stat
		git commit -m $(COMMIT)
p: com
	@$(MAKE) -C Libft push
	git push origin $(BRANCH)

merge:
	git checkout master
	git fetch
	git pull
	git merge $(BRANCH)
