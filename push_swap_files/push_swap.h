#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

struct				s_stacks
{
	int	a;
	int	avalue;
	int	b;
	int	bvalue;
};
void	sa(struct s_stacks *stack, int x);
void	sb(struct s_stacks *stack, int x);
void	pb(struct s_stacks *stack, int i);
void	pa(struct s_stacks *stack, int i);
void	ra(struct s_stacks *stack, int x);
void	rb(struct s_stacks *stack, int x);
void	rra(struct s_stacks *stack, int x);
void	rrb(struct s_stacks *stack, int x);
void	rr_rrr_ss(struct s_stacks *stack, int type);
void	ft_error(char *msg);
void	write_comm(char *comm);
void	smallest_stack(struct s_stacks *stack, int argc);
void	print(struct s_stacks *stack, int argc);
int		end_stack_a(struct s_stacks *stack);
int		end_stack_b(struct s_stacks *stack);
int		get_rot_b(struct s_stacks *stack, int value);
void	get_rot_a(struct s_stacks *stack, int argc);
int		small_check(struct s_stacks *stack);
void	place_b_near_end(struct s_stacks *stack, int argc, int end);
int		place_b_top(struct s_stacks *stack, int i, int argc);
int		find_lowest_value_a(struct s_stacks *stack);
int		find_lowest_value_above(struct s_stacks *stack, int min);
void	push_small_b(struct s_stacks *stack, int argc, int rot);
int		get_lowest_num(struct s_stacks *stack, int argc, int j);
char	**get_nums(char **argv, int argc);
int		count_char(char *str, char c);

#endif