#include "../include/push_swap.h"

/**
 * Moves the top element from stack_1 to stack_2.
 *
 * @param stack_1 Pointer to the source stack.
 * @param stack_2 Pointer to the destination stack.
 */
static void	push(t_node **stack_1, t_node **stack_2)
{
	t_node	*node;

	// If stack_1 is empty, there is nothing to push, so return.
	if (!*stack_1)
		return ;
	// Store the top node of stack_1 and move the top pointer to the next node.
	node = *stack_1;
	*stack_1 = (*stack_1)->next;
	// If the new top node exists, set its previous pointer to NULL.
	if (*stack_1)
		(*stack_1)->prev = NULL;
	node->prev = NULL;
	// If stack_2 is empty, set the node as the first element.
	if (!*stack_2)
	{
		*stack_2 = node;
		node->next = NULL;
	}
	else
	{
		 // Otherwise, push the node to the top of stack_2.
		node->next = *stack_2;
		node->next->prev = node;
		*stack_2 = node;
	}
}

// Push the top element from stack_a to stack_b
void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

// Push the top element from stack_b to stack_a
void	pa(t_node **stack_b, t_node **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}