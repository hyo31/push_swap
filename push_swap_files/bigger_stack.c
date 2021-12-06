#include "push_swap.h"

int	push_order(int *lowest_group, int j, struct s_stacks *stack)
{
	int	i;
	int	low_i;
	int	low;

	i = 1;
	low_i = 0;
	if (lowest_group[0] < stack[lowest_group[0]].avalue)
		low = lowest_group[0];
	else
		low = stack[lowest_group[0]].avalue;
	while (i < j)
	{
		if (lowest_group[i] < low || stack[lowest_group[i]].avalue < low)
			low_i = i;
		if (lowest_group[i] < low)
			low = lowest_group[i];
		if (stack[lowest_group[i]].avalue < low)
			low = stack[lowest_group[i]].avalue;
		i++;
	}
	return (lowest_group[low_i]);
}

int	get_lowest_num(struct s_stacks *stack, int argc, int j)
{
	int	i;
	int	min;
	int	low_i;
	int	*lowest_group;

	i = 1;
	min = find_lowest_value_a(stack);
	lowest_group = malloc(sizeof(int *) * j);
	lowest_group[0] = min;
	stack[min].avalue = end_stack_a(stack) - lowest_group[0];
	while (i < j && i < argc - 1)
	{
		min = find_lowest_value_above(stack, stack[min].a);
		lowest_group[i] = min;
		stack[min].avalue = end_stack_a(stack) - lowest_group[i];
		i++;
	}
	low_i = push_order(lowest_group, j, stack);
	free(lowest_group);
	return (low_i);
}

int	reverse_rotate_b(struct s_stacks *stack, int num[4], int i, int rotb)
{
	if (num[1] <= num[0] && rotb == -1 && i < num[1])
	{
		rr_rrr_ss(stack, 2);
		i++;
	}
	else if (num[0] < num[1] && rotb != 1 && i < num[0])
	{
		if (rotb)
			rrb(stack, 1);
		ra(stack, 1);
		i++;
	}
	else if ((i == num[0] || i == num[1]) && rotb == -1)
		rrb(stack, 1);
	if ((i == num[0] || i == num[1]) && rotb == 0)
		pb(stack, num[3]);
	return (i);
}

int	rotate_b(struct s_stacks *stack, int num[4], int i)
{
	int	rotb;

	rotb = get_rot_b(stack, num[2]);
	if (num[0] < num[1] && rotb == 1 && i < num[0])
	{
		rr_rrr_ss(stack, 1);
		i++;
	}
	else if (num[1] <= num[0] && rotb != -1 && i < num[1])
	{
		if (rotb)
			rb(stack, 1);
		rra(stack, 1);
		i++;
	}
	else if ((i == num[0] || i == num[1]) && rotb == 1)
		rb(stack, 1);
	return (reverse_rotate_b(stack, num, i, rotb));
}

void	push_small_b(struct s_stacks *stack, int argc, int rot)
{
	int	num[6];

	num[0] = rot;
	num[1] = stack[num[0]].avalue;
	num[2] = stack[num[0]].a;
	num[3] = argc;
	num[4] = end_stack_a(stack) - 1;
	num[5] = 0;
	while (num[5] < num[0] && num[5] < num[1] && end_stack_b(stack) <= 1)
	{
		if (num[0] < num[1])
			ra(stack, 1);
		if (num[1] <= num[0])
			rra(stack, 1);
		num[5]++;
	}
	while (stack[num[4]].avalue && end_stack_b(stack) > 1)
		num[5] = rotate_b(stack, num, num[5]);
	if (end_stack_b(stack) <= 1)
	{
		pb(stack, argc);
		if (stack[0].b < stack[1].b && stack[1].bvalue)
			sb(stack, 1);
	}
}
