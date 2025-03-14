#include "../include/push_swap.h"

/*
 * Sets the optimal target for each node in stack B.
 * The target is the smallest number in stack A that is larger than the current node in B.
 */
static void	set_target_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*a;
	t_node	*target;
	long	largest;

	while (stack_b)
	{
		largest = LONG_MAX;
		a = stack_a;
		while (a)
		{
			// Searches stack A for the smallest number that is still larger than stack_b->num
			if (a->num > stack_b->num && a->num < largest)
			{
				largest = a->num;
				target = a;
			}
			a = a->next;
		}
		// If no valid target is found, assign the smallest number in stack A as the target
		if (largest == LONG_MAX)
			stack_b->target = find_smallest(stack_a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}

/*
 * Prepares stack B for sorting by setting all necessary attributes:
 * - Position of each node
 * - Optimal target in stack A
 */
void	prepare_b(t_node *stack_a, t_node *stack_b)
{
	set_position(stack_a);
	set_position(stack_b);
	set_target_b(stack_a, stack_b);
}