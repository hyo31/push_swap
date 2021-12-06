#include "checker.h"

void	exec_command(struct s_stacks *stack, int argc, char *command)
{
	if (!ft_strncmp(command, "sa", 3))
		sa(stack);
	else if (!ft_strncmp(command, "sb", 3))
		sb(stack);
	else if (!ft_strncmp(command, "pa", 3))
		pa(stack, argc);
	else if (!ft_strncmp(command, "pb", 3))
		pb(stack, argc);
	else if (!ft_strncmp(command, "ra", 3))
		ra(stack);
	else if (!ft_strncmp(command, "rb", 3))
		rb(stack);
	else if (!ft_strncmp(command, "rra", 3))
		rra(stack);
	else if (!ft_strncmp(command, "rrb", 3))
		rrb(stack);
	else if (!ft_strncmp(command, "rr", 3))
		rr_rrr_ss(stack, 1);
	else if (!ft_strncmp(command, "rrr", 3))
		rr_rrr_ss(stack, 2);
	else if (!ft_strncmp(command, "ss", 3))
		rr_rrr_ss(stack, 3);
	else
		ft_error("Error\n");
}

int	read_commands(struct s_stacks *stack, int argc)
{
	char	*command;
	int		i;

	i = 0;
	command = get_next_line(STDIN_FILENO);
	if (!command)
		return (0);
	while (command[i] != '\n')
		i++;
	command[i] = '\0';
	exec_command(stack, argc, command);
	free(command);
	return (1);
}

int	check_stack_after(struct s_stacks *stack, int argc)
{
	int		i;

	i = 0;
	while (i < argc - 2)
	{
		if (stack[i].a > stack[i + 1].a || stack[i].b)
			return (0);
		i++;
	}
	return (1);
}
