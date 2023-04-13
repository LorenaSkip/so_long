NAME = libft.a

SRC = *.c
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

NONE='\033[0m'
GREEN='\033[32m'
LIGHTBLUE='\033[36m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE) $(LIGHTBLUE)"          - Generating $(NAME)..." $(NONE)
	@ar rc $(NAME) $(OBJ)

$(OBJ): $(SRC)
	@echo $(CURSIVE) $(GREEN)"          - Compiling libft..." $(NONE)
	@gcc $(FLAGS) -c $(SRC)

norm:
	@norminette $(SRC) libft.h

clean:
	@echo $(CURSIVE) $(LIGHTBLUE)"          - Removing libft object files..." $(NONE)
	@rm -f $(OBJ)

fclean: clean
	@echo $(CURSIVE) $(GREEN)"          - Removing $(NAME)..." $(NONE)
	@rm -f $(NAME)

re: fclean all