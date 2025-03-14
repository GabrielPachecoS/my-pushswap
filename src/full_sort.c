#include "../include/push_swap.h"

/*
 * Moves the optimal element from stack A to stack B.
 * Determines whether to use simultaneous rotations (rr or rrr),
 * then positions the element at the top of both stacks before pushing.
 */
static void	move_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*shortest;

	shortest = get_shortest(*stack_a);
	// If both the element in A and its target in B are in the upper half of their stacks
	if (shortest->upper_part && shortest->target->upper_part)
		rotate_a_b(stack_a, stack_b, shortest);
	// If both the element in A and its target in B are in the lower half of their stacks
	else if (!(shortest->upper_part) && !(shortest->target->upper_part))
		reverse_a_b(stack_a, stack_b, shortest);
	set_top_a(stack_a, shortest);
	set_top_b(stack_b, shortest->target);
	pb(stack_a, stack_b);
}
0
/*
 * Moves the top element of stack B to its correct position in stack A.
 * Positions the target in stack A before executing the push.
 */
static void	move_b(t_node **stack_a, t_node **stack_b)
{
	set_top_a(stack_a, (*stack_b)->target);
	pa(stack_b, stack_a);
}

/*
 * Positions the smallest number at the top of the stack.
 * Uses either ra or rra depending on whether the number is in the upper or lower half.
 */
static void	order_nums(t_node **stack)
{
	t_node	*smallest;

	smallest = find_smallest(*stack);
	// While stack A has more than 3 elements and is not yet sorted
	while ((*stack)->num != smallest->num)
	{
		if (smallest->upper_part)
			ra(stack);
		else
			rra(stack);
	}
}

/*
 * Implements the full sorting algorithm.
 * Moves a few elements to stack B for better sorting, sorts stack A,
 * then moves elements back from B to A in the correct order.
 * Finally, ensures the smallest element is positioned correctly.
 */
void	full_sort(t_node **stack_a, t_node **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	// Move two elements to stack B to facilitate sorting if the list has more than 3 elements
	if (len-- > 3 && !stack_done(*stack_a))
		pb(stack_a, stack_b);
	if (len-- > 3 && !stack_done(*stack_a))
		pb(stack_a, stack_b);
	// While stack A has more than 3 elements and is not yet sorted
	while (len-- > 3 && !stack_done(*stack_a))
	{
		prepare_a(*stack_a, *stack_b);
		move_a(stack_a, stack_b);
	}
	small_sort(stack_a);
	// While stack B is not empty, move elements back to A in sorted order
	while (*stack_b)
	{
		prepare_b(*stack_a, *stack_b);
		move_b(stack_a, stack_b);
	}
	set_position(*stack_a);
	order_nums(stack_a);
}