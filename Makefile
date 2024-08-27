.SILENT:

NAME = so_long

SRCS = so_long.c parsing.c image.c map.c event.c move.c set_collision.c cel.c check_collision.c quit.c ouachcaca.c update.c print.c manager.c

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CFLAGS = -Wall -Werror -Wextra -g
MLXFLAGS =  -framework OpenGL -framework AppKit

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@gcc $(CFLAGS) -Imlx -c $< -o $@

$(NAME): sub $(OBJS)
	@echo "🐥 Prépare-toi pour l'aventure mon petit pote. 🐥"
	@$(MAKE) -C ./Libft
	@$(MAKE) -C ./MinilibX
	@gcc $(CFLAGS) $(OBJS) ./Libft/libft.a MinilibX/libmlx.a $(MLXFLAGS) -o $(NAME)
	@echo "👑 LET'S GO ÇA PART ! 👑"

clean:
	@$(MAKE) -C Libft fclean
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "🏰✨💨 Le château disparaît dans un nuage de petites paillettes et de boucane sucrée... $(NAME) a été détruit !✨💨🏰"
	@rm -f $(NAME)

re: fclean all

sub:
	@git submodule update --init --recursive
