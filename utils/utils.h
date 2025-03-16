#ifndef UTILS_H
# define UTILS_H


#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;	
}	t_stack;

t_stack	*newlst(int nbr);
t_stack	*lstlast(t_stack *lst);
void	lstadd_front(t_stack **lst, t_stack *new);
void	lstadd_back(t_stack **alst, t_stack *new);
void	lstclear(t_stack **lst);
int		lstsize(t_stack *lst);

long	ft_atol(const char *s);

int		stack_is_sorted(t_stack *stack);

t_stack *find_max(t_stack *head);
t_stack *find_min(t_stack *head);

#endif