#include "push_swap.h"

int is_integer(char *s) {
    int i;

    if (!s || !s[0])
        return 0;        
    i = 0;
    if (s[0] == '-' || s[0] == '+')
        i++;
    if (!s[i])
        return 0;
    while (s[i])
	{
        if (s[i] < '0' || s[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int is_dup(char **args) {
    int i;
    int j;
    long val_i;
    long val_j;
    
    if (!args)
        return 0;
    i = 0;
    while (args[i]) {
        j = i + 1;
        val_i = ft_atoi(args[i]);
        while (args[j]) {
            val_j = ft_atoi(args[j]);
            if (val_i == val_j)
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}

int process_arg(char **arg, t_stack *stack_a);
{
	int i = 0;
	while (arg[i])
	{
		if (!is_integer(arg[i]))
			return 0;
		if (is_dup(arg, stack_a))
			return 0;
	}
	/* fill the stack  */
}

char **validate_input(int ac, char **av, t_stack *stack_a)
{
	char **args;
	int (i), (j);
	i = 0;
	j = 0;

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





// int is_integer(char **arg, t_stack *stack) {
// 	int (i);
// 	i = -1;
// 	while (s[++i]) {
// 		if (s[i] >= '0' && s[i] <= '9')
// 			continue;
// 		return 0;
// 	}
// 	return 1;
// }

// int is_dup(char *s) {
// 	int (i);
// 	i = -1;
// 	while (s[++i]) {
// 		if (s[i] >= '0' && s[i] <= '9')
// 			continue;
// 		return 1;
// 	}
// 	return 0;
// }