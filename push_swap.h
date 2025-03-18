/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <rajianwar421@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:21:46 by araji             #+#    #+#             */
/*   Updated: 2025/03/18 00:21:46 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "utils/utils.h"
#include "operations/operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct _vars {
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*array;
}	t_vars;

/* main.c */
int		*generate_array(t_stack **head, int size);
void	selection_sort(int **array, int size);
void	cleanup(t_stack **a, t_stack **b, int *int_array);


/* validate_input.c */
void	free_args(char **);
int		is_integer(char *s);
int		fill_nd_check_dup(char **args, t_stack **stack_a);
int		process_arg(char **arg, t_stack **stack_a);
int		validate_input(int ac, char **av, t_stack **stack_a);

/* big_sort.c */
void	rot_direction(t_stack **a, int *arr, int chunk_max);
int		max_in_first_half(t_stack **stack, int size, int max);
void	updateindex(int *i, int *j, int size);
void	swapback(t_stack **a, t_stack **b, int n);
void	bigsort(t_stack **a, t_stack **b, int *array_of_ints, int size);
int		get_range(int size);

/* small_sort.c */
void	sort3(t_stack **a);
void	sort5(t_stack **a, t_stack **b);

#endif