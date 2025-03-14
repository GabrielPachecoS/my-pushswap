#include "../include/push_swap.h"

// Function to sort a stack of 3 elements with minimal operations
void	small_sort(t_node **stack)
{
	t_node	*largest;

	largest = find_largest(*stack);
	// Check if the largest element is already in the right position
	if (largest == *stack)
		ra(stack);
	else if (largest == (*stack)->next)
		rra(stack);
	// Perform a swap if the first two elements are not in the correct order
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
}