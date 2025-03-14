#include "../include/push_swap.h"

/*
 * Swaps the first two elements of the given stack.
 * Updates the necessary pointers to maintain the 
 * doubly linked list structure.
 */
static void	swap(t_node **stack)
{
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

/*
 * Executes 'sa' (swap a): swaps the first two elements of stack A.
 * Prints "sa" to indicate the operation.
 */	
void	sa(t_node **stack)
{
	swap(stack);
	ft_printf("sa\n");
}

/*
 * Executes 'sb' (swap b): swaps the first two elements of stack B.
 * Prints "sb" to indicate the operation.
 */
void	sb(t_node **stack)
{
	swap(stack);
	ft_printf("sb\n");
}

/*
 * Executes 'ss' (swap both): swaps the first two elements of both stack A and stack B.
 * Prints "ss" to indicate the operation.
 */
void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}