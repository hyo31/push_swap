#include "checker.h"

void	sa(struct s_stacks *stack)
{
	int		temp;

	if (!stack[0].avalue || !stack[1].avalue)
		return ;
	temp = stack[0].a;
	stack[0].a = stack[1].a;
	stack[1].a = temp;
}

void	sb(struct s_stacks *stack)
{
	int		temp;

	if (!stack[0].bvalue || !stack[1].bvalue)
		return ;
	temp = stack[0].b;
	stack[0].b = stack[1].b;
	stack[1].b = temp;
}

void	pb(struct s_stacks *stack, int i)
{
	if (!stack[0].avalue)
		return ;
	while (i > 0)
	{
		stack[i].b = stack[i - 1].b;
		stack[i].bvalue = stack[i - 1].bvalue;
		i--;
	}
	stack[0].b = stack[0].a;
	stack[0].bvalue = stack[0].avalue;
	while (stack[i].avalue)
	{
		stack[i].a = stack[i + 1].a;
		stack[i].avalue = stack[i + 1].avalue;
		i++;
	}
}

void	pa(struct s_stacks *stack, int i)
{
	if (!stack[0].bvalue)
		return ;
	while (i > 0)
	{
		stack[i].a = stack[i - 1].a;
		stack[i].avalue = stack[i - 1].avalue;
		i--;
	}
	stack[0].a = stack[0].b;
	stack[0].avalue = stack[0].bvalue;
	while (stack[i].bvalue)
	{
		stack[i].b = stack[i + 1].b;
		stack[i].bvalue = stack[i + 1].bvalue;
		i++;
	}
}
