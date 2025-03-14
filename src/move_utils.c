#include "../include/push_swap.h"

/*
 * Moves the given node to the top of stack A.
 * Uses 'ra' (rotate) if the node is in the upper part,
 * otherwise, it uses 'rra' (reverse rotate).
 */
void	set_top_a(t_node **stack, t_node *top)
{
	while (*stack != top)
	{
		if (top->upper_part)
			ra(stack);
		else
			rra(stack);
	}
}

/*
 * Moves the given node to the top of stack B.
 * Uses 'rb' (rotate) if the node is in the upper part,
 * otherwise, it uses 'rrb' (reverse rotate).
 */
void	set_top_b(t_node **stack, t_node *top)
{
	while (*stack != top)
	{
		if (top->upper_part)
			rb(stack);
		else
			rrb(stack);
	}
}

/*
 * Rotates both stack A and stack B simultaneously
 * using 'rr' until the shortest-cost node in A 
 * and its target node in B are at the top.
 * Updates positions after rotation.
 */
void	rotate_a_b(t_node **stack_a, t_node **stack_b, t_node *shortest)
{
	while (*stack_a != shortest && *stack_b != shortest->target)
		rr(stack_a, stack_b);
	set_position(*stack_a);
	set_position(*stack_b);
}

/*
 * Reverse rotates both stack A and stack B simultaneously
 * using 'rrr' until the shortest-cost node in A 
 * and its target node in B are at the top.
 * Updates positions after rotation.
 */
void	reverse_a_b(t_node **stack_a, t_node **stack_b, t_node *shortest)
{
	while (*stack_a != shortest && *stack_b != shortest->target)
		rrr(stack_a, stack_b);
	set_position(*stack_a);
	set_position(*stack_b);
}