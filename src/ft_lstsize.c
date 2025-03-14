#include "../include/push_swap.h"

int	ft_lstsize(t_node *lst)
{
	t_node	*list;
	int		count;

	count = 0;
	list = lst;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}