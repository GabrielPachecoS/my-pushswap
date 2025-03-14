
#include "../include/push_swap.h"

// Function to reverse rotate a stack (move last element to the front)
static void	reverse_rotate(t_node **stack)
{
	t_node	*last_node;

	last_node = ft_lstlast(*stack);
	last_node->prev->next = NULL;
	(*stack)->prev = last_node;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
}

// Reverse rotate stack_a (move last element to the front)
void	rra(t_node **stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

// Reverse rotate stack_b (move last element to the front)
void	rrb(t_node **stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

// Reverse rotate both stack_a and stack_b
void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}