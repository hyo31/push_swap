#include <stdio.h>
#include "push_swap.h"

void	check_stack(struct s_stacks *stack, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 2)
	{
		j = 0;
		if (stack[j].a < -2147483648 || stack[j].a > 2147483647)
			ft_error("Error\n");
		while (j < argc - 1)
		{
			if (stack[i].a == stack[j].a && i != j)
				ft_error("Error\n");
			j++;
		}
		i++;
	}
	i = 0;
	while (i < argc - 2)
	{
		if (stack[i].a > stack[i + 1].a)
			return ;
		i++;
	}
	exit(0);
}

void	is_num(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (num[i] != '-')
			if (!ft_isdigit(num[i]))
				ft_error("Error\n");
		i++;
	}
}

struct s_stacks	*create_stacks(struct s_stacks *stack, char **argv, int argc)
{
	int		i;
	char	**nums;

	i = 0;
	nums = get_nums(argv, argc);
	while (nums[i])
	{
		is_num(nums[i]);
		stack[i].a = ft_atoi(nums[i]);
		free(nums[i]);
		stack[i].avalue = 1;
		stack[i].b = 0;
		stack[i].bvalue = 0;
		i++;
	}
	free(nums);
	stack[i].a = 0;
	stack[i].avalue = 0;
	stack[i].b = 0;
	stack[i].bvalue = 0;
	check_stack(stack, end_stack_a(stack) + 1);
	return (stack);
}

void	bigger_stack(struct s_stacks *stack, int argc, int jsize)
{
	int	j;
	int	min;

	min = find_lowest_value_a(stack);
	j = jsize;
	while (stack[5].avalue)
	{
		while (j > 0)
		{
			push_small_b(stack, argc, get_lowest_num(stack, argc, j));
			j--;
		}
		j = jsize;
		if (j >= end_stack_a(stack) - 1)
			j = end_stack_a(stack) - 5;
	}
	while (stack[end_stack_b(stack) - 1].b > stack[0].b)
		rrb(stack, 1);
	if (!small_check(stack))
		smallest_stack(stack, argc);
	get_rot_a(stack, argc);
}

int	main(int argc, char **argv)
{
	struct s_stacks	*stack;

	if (argc < 2)
		return (0);
	if (argc == 2)
		stack = (struct s_stacks *)malloc(sizeof(struct s_stacks)
				* (count_char(argv[1], ' ') + 2));
	else
		stack = (struct s_stacks *)malloc(sizeof(struct s_stacks) * (argc + 1));
	if (!stack)
		ft_error("Error\n");
	stack = create_stacks(stack, argv, argc);
	argc = end_stack_a(stack) + 1;
	if (argc < 6)
		smallest_stack(stack, argc);
	else
	{
		if (argc >= 351)
			bigger_stack(stack, argc, 42);
		else
			bigger_stack(stack, argc, (argc - 1) / 5);
	}
	free(stack);
	return (0);
}
