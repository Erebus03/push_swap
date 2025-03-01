#include "push_swap.h"

int is_integer(char *s) {
	int (i);
	i = -1;
	while (s[++i]) {
		if (s[i] >= '0' && s[i] <= '9')
			continue;
		return 0;
	}
	return 1;
}

int process_arg(char **arg, t_stack *stack_a);

char **validate_input(int ac, char **av, t_stack *stack_a)
{
	char **args;
	int (i), (j);
	i = 0;
	j = 0;
	
	args = (char **)malloc(ac * sizeof(char *));
	
	while (++j < ac)
	{
		args = ft_split(av[j], ' ');
		if (!process_arg(args, stack_a))
		{
			free_args(args);
			return NULL;
		}
	}
	args[ac - 1] = NULL;
	
	free_args(ac, args);
	return args;
}




// for (int k = 0; --j ; k++) {
// 		i = 0;
// 		while (args[k][i] != NULL) {
// 					printf("%s\n", args[k][i]);
// 					i++;
// 			}
// 		}
		




// int	convert_check_args(int ac, char **args)
// {
// 	int (i), (k);
// 	i = 0;
// 	k = 0;

// 	while (--ac) {
// 		i = 0;
// 		while (args[k][i] != NULL) {
// 			if (!is_integer(args[k][i]))
// 				return 0;
// 			i++;
// 		}
// 		k++;
// 	}
// 	return 1;
// }