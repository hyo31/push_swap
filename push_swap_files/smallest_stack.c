#include "push_swap.h"

void	smallest(struct s_stacks *stack)
{
	if (stack[0].a > stack[1].a)
		sa(stack, 1);
}

int	small_check(struct s_stacks *stack)
{
	int	i;

	i = 0;
	while (stack[i + 1].avalue)
	{
		if (stack[i].a > stack[i + 1].a)
			return (0);
		i++;
	}
	return (1);
}

void	smaller(struct s_stacks *stack)
{
	if (stack[0].a > stack[1].a && stack[0].a < stack[2].a)
		sa(stack, 1);
	else if (stack[0].a > stack[1].a && stack[0].a > stack[2].a
		&& stack[1].a > stack[2].a)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (stack[0].a > stack[1].a && stack[0].a > stack[2].a
		&& stack[1].a < stack[2].a)
		ra(stack, 1);
	else if (stack[0].a < stack[1].a && stack[0].a < stack[2].a)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (stack[0].a < stack[1].a && stack[0].a > stack[2].a)
		rra(stack, 1);
}

int	get_commands(struct s_stacks *stack, int argc, int i)
{
	int	end;

	end = end_stack_a(stack);
	if (stack[0].a > stack[0].b)
		i = place_b_top(stack, i, argc);
	else if (stack[end - 1].a > stack[0].b && stack[0].b > stack[end - 2].a)
		place_b_near_end(stack, argc, end);
	else if (stack[0].b > stack[end - i - 1].a)
	{
		pa(stack, argc);
		ra(stack, 1);
	}
	else
	{
		ra(stack, 1);
		i++;
	}
	return (i);
}

void	smallest_stack(struct s_stacks *stack, int argc)
{
	int	i;
	int	end_b;
	int	end_a;

	i = 0;
	end_b = end_stack_b(stack);
	end_a = end_stack_a(stack);
	if (end_a == 2)
		smallest(stack);
	else if (end_a == 3)
		smaller(stack);
	else
	{
		if (end_a == 5)
			pb(stack, argc);
		pb(stack, argc);
		if (!small_check(stack))
			smaller(stack);
		while (stack[end_b].bvalue)
			i = get_commands(stack, argc, i);
	}
}
