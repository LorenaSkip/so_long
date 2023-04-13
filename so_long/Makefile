NAME = so_long.out

SRC = $(MAIN_SRC) $(SRC_ERR) $(SRC_GNL) $(SRC_MAP) $(SRC_GAME)

MAIN_SRC = main.c errors.c

LIBFT_A = libft.a
LIBF_DIR = libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

GNL = get_next_line.c get_next_line_utils.c
SRC_GNL = $(addprefix gnl/, $(GNL))

MAP = 	map_checker.c map_checker_utils.c map_gastlygen.c map_reader.c map_tilegen.c
SRC_MAP = $(addprefix map/, $(MAP))

GAME =	follower_moving.c gastly_moving.c game_end.c game_init.c input.c kill_player.c op_images.c op_panel.c op_wall_images.c player_movement.c put_wall.c render.c reset.c update.c
SRC_GAME = $(addprefix lavandonia/, $(GAME))

OBJ = *.o

FLAGS = -Wall -Wextra -Werror
INCLUDE = -lmlx -framework OpenGL -framework AppKit

NONE='\033[0m'
RED='\033[31m'
LIGHTBLUE='\033[36m'
GREEN='\033[32m'
YELLOW='\033[33m'
BOLD='\033[1m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(LIGHTBLUE) "     - Making libft..." $(NONE)
	@make -C $(LIBF_DIR)
	@echo $(CURSIVE)$(LIGHTBLUE) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(LIBFT) $(INCLUDE) -o $(NAME)
	@echo $(BOLD)$(GREEN)"- Compiled -"$(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(LIGHTBLUE) "     - Making object files..." $(NONE)
	@gcc $(FALGS) -c $(SRC)

exe: re
	@make -C ./ clean
	@echo $(CURSIVE)$(YELLOW)"     - Executing $(NAME)... \n"$(NONE)
	@./$(NAME) $(m)
	@echo $(GREEN)"\n     - Done -"$(NONE)

play: all
	@echo $(YELLOW)"     - Playing all maps... \n"$(NONE)
	@make -C ./ clean
	@./$(NAME) map_files/map_1.ber
	@./$(NAME) map_files/map_2.ber
	@./$(NAME) map_files/map_3.ber
	@./$(NAME) map_files/map_4.ber
	@./$(NAME) map_files/map_5.ber
	@./$(NAME) map_files/map_final.ber
	@./$(NAME) map_files/map_b42.ber

norm:
	@echo $(RED) " "
	@norminette $(SRC) *.h */*.h
	@echo $(NONE) " "

libftnorm:
	@echo $(RED) " "
	@make -C $(LIBF_DIR) norm
	@echo $(NONE) " "

clean:
	@echo $(CURSIVE)$(RED) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)
	@make -C $(LIBF_DIR) clean

fclean: clean
	@echo $(CURSIVE)$(RED) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make -C $(LIBF_DIR) fclean

re: fclean all
