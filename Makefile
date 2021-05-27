NAME		= push_swap

SRCS		= chunk_srt.c
SRCS		+= main.c
SRCS		+= push.c
SRCS		+= rotate.c
SRCS		+= solver.c
SRCS		+= srt_utils.c
SRCS		+= swap.c
SRCS		+= stk_builder.c
SRCS		+= stk_clear.c
SRCS		+= stk_utils.c

OBJ_DIR		= ./srcs/obj/
PS_DIR		= ./srcs/push_swap/

LIBFT_DIR	= ./srcs/libft/
GNL_DIR		= ./srcs/gnl/
LIBFT_A		= $(addprefix $(LIBFT_DIR), libft.a)
GNL_A		= $(addprefix $(GNL_DIR), get_next_line.a)
OBJ			= $(addprefix $(OBJ_DIR),$(SRCS:.c=.o))
INC			= ./srcs/push_swap/ps.h

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
RM_DIR		= rm -rf

all:
	mkdir -p $(OBJ_DIR)
	make -C $(LIBFT_DIR) --no-print-directory
	make -C $(GNL_DIR) --no-print-directory
	$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)%.o:$(PS_DIR)%.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):$(OBJ) $(INC) $(LIBFT_A) $(GNL_A)
	$(CC) $(CFLAGS) $(OBJ) $(GNL_A) $(LIBFT_A) -o $(NAME)

clean:
	$(RM_DIR) $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(GNL_DIR)

fclean:
	$(RM_DIR) $(OBJ_DIR)
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(GNL_DIR)

re:fclean all

.PHONY:all clean fclean re