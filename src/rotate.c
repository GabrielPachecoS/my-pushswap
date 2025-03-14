#include "../include/push_swap.h"

// Function to rotate a stack (move the first element to the last)
static void	rotate(t_node **stack)
{
	t_node	*last_node;

	last_node = ft_lstlast(*stack);
	*stack = (*stack)->next;
	(*stack)->prev->prev = last_node;
	(*stack)->prev->next = NULL;
	last_node->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

// Rotate stack_a (move the first element to the last)
void	ra(t_node **stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

// Rotate stack_b (move the first element to the last)
void	rb(t_node **stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

// Rotate both stack_a and stack_b
void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}