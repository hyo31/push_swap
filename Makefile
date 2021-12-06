NAME = push_swap checker
COMP = gcc -Wall -Wextra -Werror

PUSH_SWAP_SRC = $(addprefix push_swap_files/,commands.c commands1.c smallest_stack.c \
							smallest_stack_utils.c bigger_stack.c bigger_stack_utils.c push_swap.c push_swap_utils.c)
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)

GNL_SRC = $(addprefix get_next_line/,get_next_line.c get_next_line_utils.c)
CHECKER_SRC = $(addprefix checker_files/,checker.c checker_utils.c checker_utils_2.c \
							commands.c commands1.c $(GNL_SRC))
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

all: libft.a $(NAME)

libft.a: libft/
	@make -C libft/

push_swap: libft.a $(PUSH_SWAP_OBJ)
	@$(COMP) -o push_swap $(PUSH_SWAP_OBJ) libft/libft.a

checker: libft.a $(CHECKER_OBJ)
	@$(COMP) -o checker $(CHECKER_OBJ) libft/libft.a

%.o: %.c
	@$(COMP) -c $< -o $@

clean:
	@rm -f $(PUSH_SWAP_OBJ) $(CHECKER_OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
