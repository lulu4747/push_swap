NAME	= get_next_line.a

SRC		= get_next_line.c

INC = get_next_line.h
OBJ_DIR = ./obj/
OBJ = $(addprefix $(OBJ_DIR),$(notdir $(SRC:%.c=%.o)))

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

all:
	mkdir -p $(OBJ_DIR)
	$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)%.o : %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(INC)
	ar rc $(NAME) $(OBJ) $(INC)

clean:
	rm -rf $(OBJ)
	rm -rf $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY : re fclean clean all