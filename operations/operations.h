/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <rajianwar421@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:19:00 by araji             #+#    #+#             */
/*   Updated: 2025/03/18 00:19:00 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../push_swap.h"

/* push_swap_ops.c */
void	sa(t_stack **a, int is_ss_call);
void	sb(t_stack **b, int is_ss_call);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

/* rev_rotate.c */
void	ra(t_stack **a, int is_rr_call);
void	rb(t_stack **b, int is_rr_call);
void	rr(t_stack **a, t_stack **b);

/* rotate.c */
void	rra(t_stack **a, int is_rrr_call);
void	rrb(t_stack **b, int is_rrr_call);
void	rrr(t_stack **a, t_stack **b);

#endif