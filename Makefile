NAME			= push_swap

SRCS			= chunk_srt.c
SRCS			+= cmd_utils.c
SRCS			+= finder.c
SRCS			+= main.c
SRCS			+= push.c
SRCS			+= rotate.c
SRCS			+= solver.c
SRCS			+= srt_utils.c
SRCS			+= swap.c
SRCS			+= stk_builder.c
SRCS			+= stk_clear.c
SRCS			+= stk_utils.c

OBJ_DIR			= ./srcs/obj/
PS_DIR			= ./srcs/push_swap/

LIBFT_DIR		= ./srcs/libft/
LIBFT_A			= $(addprefix $(LIBFT_DIR), libft.a)
OBJ				= $(addprefix $(OBJ_DIR),$(SRCS:.c=.o))
INC				= ./srcs/push_swap/ps.h

GNL_DIR			= ./srcs/gnl/
GNL_A			= $(addprefix $(GNL_DIR), get_next_line.a)

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
RM				= rm -f
RM_DIR			= rm -rf

all:
	mkdir -p $(OBJ_DIR)
	make -C $(LIBFT_DIR) --no-print-directory
	$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)%.o:$(PS_DIR)%.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):$(OBJ) $(INC) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) -o $(NAME)

clean:
	$(RM_DIR) $(OBJ_DIR)
	$(RM_DIR) $(OBJ_DIR_BONUS)
	$(MAKE) clean -C $(GNL_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean:
	$(RM_DIR) $(OBJ_DIR)
	$(RM) $(NAME)
	$(RM_DIR) $(OBJ_DIR_BONUS)
	$(RM) $(NAME_BONUS)
	$(MAKE) fclean -C $(GNL_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)

NAME_BONUS		= checker_bonus

SRCS_BONUS		= is_sorted.c
SRCS_BONUS		+= main.c
SRCS_BONUS		+= push.c
SRCS_BONUS		+= rotate.c
SRCS_BONUS		+= srt_utils.c
SRCS_BONUS		+= stk_builder.c
SRCS_BONUS		+= stk_clear.c
SRCS_BONUS		+= swap.c

TEST_DIR		= ./srcs/tester/
OBJ_DIR_BONUS	= ./srcs/obj_bonus/

OBJ_BONUS		= $(addprefix $(OBJ_DIR_BONUS),$(SRCS_BONUS:.c=.o))
INC_BONUS		= ./srcs/tester/tester.h

bonus:all
	mkdir -p $(OBJ_DIR_BONUS)
	make -C $(GNL_DIR) --no-print-directory
	$(MAKE) $(NAME_BONUS) --no-print-directory

$(OBJ_DIR_BONUS)%.o:$(TEST_DIR)%.c $(INC_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS):$(OBJ_BONUS) $(INC_BONUS) $(LIBFT_A) $(GNL_A)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(GNL_A) $(LIBFT_A) -o $(NAME_BONUS)

re:fclean all

re_bonus:fclean bonus

.PHONY:all clean fclean bonus re re_bonus