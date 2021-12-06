#include "push_swap.h"

void	ra(struct s_stacks *stack, int x)
{
	int		i;
	int		end;
	int		temp;
	int		tempvalue;

	i = 0;
	end = 0;
	if (x)
		write_comm("ra");
	while (stack[end + 1].avalue)
		end++;
	temp = stack[0].a;
	tempvalue = stack[0].avalue;
	while (i < end)
	{
		stack[i].a = stack[i + 1].a;
		stack[i].avalue = stack[i + 1].avalue;
		i++;
	}
	stack[i].a = temp;
	stack[i].avalue = tempvalue;
}

void	rb(struct s_stacks *stack, int x)
{
	int		i;
	int		end;
	int		temp;
	int		tempvalue;

	i = 0;
	end = 0;
	if (x)
		write_comm("rb");
	while (stack[end + 1].bvalue)
		end++;
	temp = stack[0].b;
	tempvalue = stack[0].bvalue;
	while (i < end)
	{
		stack[i].b = stack[i + 1].b;
		stack[i].bvalue = stack[i + 1].bvalue;
		i++;
	}
	stack[i].b = temp;
	stack[i].bvalue = tempvalue;
}

void	rra(struct s_stacks *stack, int x)
{
	int		i;
	int		temp;
	int		tempvalue;

	i = 0;
	if (x)
		write_comm("rra");
	while (stack[i + 1].avalue)
		i++;
	temp = stack[i].a;
	tempvalue = stack[i].avalue;
	while (i > 0)
	{
		stack[i].a = stack[i - 1].a;
		stack[i].avalue = stack[i - 1].avalue;
		i--;
	}
	stack[i].a = temp;
	stack[i].avalue = tempvalue;
}

void	rrb(struct s_stacks *stack, int x)
{
	int		i;
	int		temp;
	int		tempvalue;

	i = 0;
	if (x)
		write_comm("rrb");
	while (stack[i + 1].bvalue)
		i++;
	temp = stack[i].b;
	tempvalue = stack[i].bvalue;
	while (i > 0)
	{
		stack[i].b = stack[i - 1].b;
		stack[i].bvalue = stack[i - 1].bvalue;
		i--;
	}
	stack[i].b = temp;
	stack[i].bvalue = tempvalue;
}

void	rr_rrr_ss(struct s_stacks *stack, int type)
{
	if (type == 1)
	{
		write_comm("rr");
		ra(stack, 0);
		rb(stack, 0);
	}
	if (type == 2)
	{
		write_comm("rrr");
		rra(stack, 0);
		rrb(stack, 0);
	}
	if (type == 3)
	{
		write_comm("ss");
		sa(stack, 0);
		sb(stack, 0);
	}
}
