#ifndef CHECKER_H
# define CHECKER_H

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
char	*get_next_line(int fd);
void	sa(struct s_stacks *stack);
void	sb(struct s_stacks *stack);
void	pb(struct s_stacks *stack, int i);
void	pa(struct s_stacks *stack, int i);
void	ra(struct s_stacks *stack);
void	rb(struct s_stacks *stack);
void	rra(struct s_stacks *stack);
void	rrb(struct s_stacks *stack);
void	rr_rrr_ss(struct s_stacks *stack, int type);
int		read_commands(struct s_stacks *stack, int argc);
int		check_stack_after(struct s_stacks *stack, int argc);
void	ft_error(char *msg);
char	**get_nums(char **argv, int argc);
int		count_char(char *str, char c);
int		end_stack_a(struct s_stacks *stack);

#endif