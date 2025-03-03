#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../push_swap.h"

void	sa(t_stack **, int is_ss_call);
void	sb(t_stack **, int is_ss_call);
void	ss(t_stack **, t_stack **);

void	pa(t_stack **, t_stack **);
void	pb(t_stack **, t_stack **);

void	ra(t_stack **, int is_rr_call);
void	rra(t_stack **, int is_rrr_call);

void	rb(t_stack **, int is_rr_call);
void	rrb(t_stack **, int is_rrr_call);

void	rr(t_stack **, t_stack **);
void	rrr(t_stack **, t_stack **);

#endif