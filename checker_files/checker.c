#include "checker.h"

void	ft_error(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(1);
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

int	main(int argc, char **argv)
{
	struct s_stacks	*stack;
	int				i;

	i = 1;
	if (argc < 2)
		return (0);
	if (argc == 2)
		stack = (struct s_stacks *)malloc(sizeof(struct s_stacks)
				* (count_char(argv[1], ' ') + 3));
	else
		stack = (struct s_stacks *)malloc(sizeof(struct s_stacks) * (argc + 1));
	if (!stack)
		ft_error("Error\n");
	stack = create_stacks(stack, argv, argc);
	argc = end_stack_a(stack) + 1;
	while (i)
		i = read_commands(stack, argc);
	if (!check_stack_after(stack, argc))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(stack);
	return (0);
}
