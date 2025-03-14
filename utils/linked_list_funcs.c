#include "utils.h"

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = lstlast(*lst);
	if (!last_node)
		*lst = new;
	new->prev = last_node;
	last_node->next = new;
}

void	lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		new->next = NULL;
		new->prev = NULL;
		*lst = new;
		return ;
	}
	(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
}

void	lstclear(t_stack **lst)
{
	t_stack	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	free (*lst);
	*lst = NULL;
	lst = NULL;
}

t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*newlst(int nbr)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}


/*  NOT REALLY USING IT */
int	lstsize(t_stack *lst)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = lst;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}




// void	lstiter(t_stack *lst, int (*f)(int))
// {
// 	if (!lst || !f)
// 		return ;
// 	while (lst)
// 	{
// 		f(lst->nbr);
// 		lst = lst->next;
// 	}
// }










// t_stack	*lstmap(t_stack *lst, int (*f)(int), void (*del)(int))
// {
// 	t_stack	*new_node;
// 	t_stack	*edited_node;
// 	int		edited_nbr;

// 	if (!lst || !f || !del)
// 		return (NULL);
// 	new_node = NULL;
// 	while (lst)
// 	{
// 		edited_nbr = f(lst->nbr);
// 		edited_node = newlst(edited_nbr);
// 		if (!edited_node)
// 		{
// 			del(edited_nbr);
// 			lstclear(&new_node);
// 			return (NULL);
// 		}
// 		lstadd_back(&new_node, edited_node);
// 		lst = lst->next;
// 	}
// 	return (new_node);
// }