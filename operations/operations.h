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
void	sa(t_stack **, int is_ss_call);
void	sb(t_stack **, int is_ss_call);
void	ss(t_stack **, t_stack **);
void	pa(t_stack **, t_stack **);
void	pb(t_stack **, t_stack **);

/* rev_rotate.c */
void	ra(t_stack **, int is_rr_call);
void	rb(t_stack **, int is_rr_call);
void	rr(t_stack **, t_stack **);

/* rotate.c */
void	rra(t_stack **, int is_rrr_call);
void	rrb(t_stack **, int is_rrr_call);
void	rrr(t_stack **, t_stack **);

#endif