#include "push_swap.h"

int	find_lowest_value_above(struct s_stacks *stack, int min)
{
	int	i;
	int	low_value;
	int	low_i;

	i = 0;
	while (stack[i].avalue)
	{
		if (stack[i].a > min)
		{
			low_value = stack[i].a;
			low_i = i;
		}
		i++;
	}
	i = 1;
	while (stack[i].avalue)
	{
		if (low_value > stack[i].a && stack[i].a > min)
		{
			low_value = stack[i].a;
			low_i = i;
		}
		i++;
	}
	return (low_i);
}

int	find_lowest_value_a(struct s_stacks *stack)
{
	int	i;
	int	low_value;
	int	low_i;

	i = 1;
	low_value = stack[0].a;
	low_i = 0;
	while (stack[i].avalue)
	{
		if (low_value > stack[i].a)
		{
			low_value = stack[i].a;
			low_i = i;
		}
		i++;
	}
	return (low_i);
}

int	find_lowest_value_b(struct s_stacks *stack)
{
	int	i;
	int	low_value;
	int	low_i;

	i = 1;
	low_value = stack[0].b;
	low_i = 0;
	while (stack[i].bvalue)
	{
		if (low_value > stack[i].b)
		{
			low_value = stack[i].b;
			low_i = i;
		}
		i++;
	}
	return (low_i);
}

void	get_rot_a(struct s_stacks *stack, int argc)
{
	int	end_b;
	int	end_a;

	while (stack[0].bvalue)
	{
		end_b = end_stack_b(stack) - 1;
		while (stack[end_b].bvalue)
		{
			end_a = end_stack_a(stack) - 1;
			if (stack[0].a > stack[0].b
				&& (stack[end_a].a > stack[0].b && stack[end_a].a < stack[0].a))
				rra(stack, 1);
			else if (stack[0].a > stack[0].b)
				pa(stack, argc);
			else
				ra(stack, 1);
		}
	}
	while (stack[end_stack_a(stack) - 1].a < stack[0].a)
		rra(stack, 1);
}

int	get_rot_b(struct s_stacks *stack, int value)
{
	int	end_b;
	int	low_b;

	end_b = end_stack_b(stack) - 1;
	low_b = find_lowest_value_b(stack);
	if (value < stack[low_b].b && low_b == end_b)
		return (0);
	else if (value < stack[low_b].b && low_b > end_b / 2)
		return (-1);
	else if (value < stack[low_b].b && low_b <= end_b / 2)
		return (1);
	else if (value > stack[0].b && (stack[end_b].b > stack[0].b
			&& stack[end_b].b < value))
		return (-1);
	else if (value > stack[0].b)
		return (0);
	else
		return (1);
}
