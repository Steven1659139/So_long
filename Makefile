NAME = so_long

SRCS = so_long.c parsing.c image.c map.c event.c move.c set_collision.c cel.c check_collision.c quit.c ouachcaca.c update.c print.c manager.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

MLXFLAGS =  -framework OpenGL -framework AppKit

BRANCH ?= $(shell bash -c 'read -p "Branch: " branch; echo $$branch')
COMMIT ?= $(shell bash -c 'read -p "Commit: " commit; echo $$commit')
ANSWER ?= $(shell bash -c 'read -p "Is OK ? " answer; echo $$answer')

# %.o: %.c
# 	gcc $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./MinilibX
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

norm:
	norminette *.c *.h

update:
	git fetch
	git pull origin $(BRANCH)

init:
	git submodule update --init --recursive
	./clone_branch.sh

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
go:
	git checkout $(BRANCH)

test:
	./test_so_long/tester_so_long.sh