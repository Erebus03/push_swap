/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:21:42 by araji             #+#    #+#             */
/*   Updated: 2025/03/18 01:41:47 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		free(args[i]);
		args[i] = NULL;
	}
	free(args);
	args = NULL;
}

int	is_integer(char *s)
{
	int	i;

	if (!s || !s[0])
		return (0);
	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	fill_nd_check_dup(char **args, t_stack **stack)
{
	t_stack	*tmp;
	long	nbr;
	int		i;

	if (!args)
		return (0);
	i = 0;
	while (args[i])
	{
		tmp = *stack;
		nbr = ft_atol(args[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (1);
		while ((tmp) != NULL)
		{
			if (nbr == (tmp)->nbr)
				return (1);
			(tmp) = (tmp)->next;
		}
		lstadd_back(stack, newlst(nbr));
		i++;
	}
	return (0);
}

int	process_arg(char **arg, t_stack **stack_a)
{
	int	i;

	i = -1;
	if (!arg || !stack_a)
		return (0);
	while (arg[++i])
		if (!is_integer(arg[i]))
			return (0);
	if (fill_nd_check_dup(arg, stack_a))
		return (0);
	return (1);
}

int	validate_input(int ac, char **av, t_stack **stack_a)
{
	char	**args;
	int		j;

	j = 0;
	args = NULL;
	while (++j < ac)
	{
		if (!av[j][0])
		{
			printf("Error\n");
			return (0);
		}
		args = ft_split(av[j], ' ');
		if (!process_arg(args, stack_a))
		{
			printf("Error\n");
			free_args(args);
			return (0);
		}
		free_args(args);
	}
	return (1);
}
