#include "push_swap.h"

char	**get_nums(char **argv, int argc)
{
	int		i;
	char	**nums;

	i = 0;
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	nums = (char **)malloc(sizeof(char *) * (argc + 1));
	while (i < argc - 1)
	{
		nums[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	nums[i] = NULL;
	return (nums);
}

int	count_char(char *str, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] == c)
			x++;
		i++;
	}
	return (x);
}
