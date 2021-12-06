#include "push_swap.h"

void	ft_error(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(1);
}

int	end_stack_a(struct s_stacks *stack)
{
	int	i;

	i = 0;
	while (stack[i].avalue)
		i++;
	return (i);
}

int	end_stack_b(struct s_stacks *stack)
{
	int	i;

	i = 0;
	while (stack[i].bvalue)
		i++;
	return (i);
}

int	place_b_top(struct s_stacks *stack, int i, int argc)
{
	pa(stack, argc);
	while (i > 0)
	{
		while (stack[0].b > stack[0].a && stack[0].bvalue
			&& stack[0].b < stack[end_stack_a(stack) - i - 1].a)
		{
			ra(stack, 1);
			i++;
			if (stack[0].b < stack[0].a && stack[0].bvalue)
				pa(stack, argc);
		}
		rra(stack, 1);
		i--;
	}
	return (i);
}

void	place_b_near_end(struct s_stacks *stack, int argc, int end)
{
	rra(stack, 1);
	pa(stack, argc);
	if (stack[0].a > stack[0].b && stack[0].b > stack[end].a && stack[0].bvalue)
	{	
		pa(stack, argc);
		ra(stack, 1);
	}
	ra(stack, 1);
	if (stack[0].b > stack[end_stack_a(stack) - 1].a
		&& stack[0].b < stack[0].a && stack[0].bvalue)
	{
		pa(stack, argc);
		ra(stack, 1);
	}
	ra(stack, 1);
}
