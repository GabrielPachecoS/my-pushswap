#include "../include/push_swap.h"

/*
 * Assigns positional attributes to each node in the stack.
 * Determines whether the node is in the upper or lower half.
 */
void	set_position(t_node *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (!stack)
		return ;
	middle = ft_lstsize(stack) / 2;
	// Iterates through the stack to assign position and region (upper/lower)
	while (stack)
	{
		stack->position = i;
		// If the position is in the first half, mark as upper_part
		if (i <= middle)
			stack->upper_part = true;
		else
			stack->upper_part = false;
		stack = stack->next;
		i++;
	}
}

/*
 * Sets the optimal target for each node in stack A.
 * The target is the largest number in stack B that is smaller than the current node in A.
 */
static void	set_target_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*b;
	t_node	*target;
	long	smallest;

	while (stack_a)
	{
		smallest = LONG_MIN;
		b = stack_b;
		// Searches stack B for the largest number that is still smaller than stack_a->num
		while (b)
		{
			if (b->num < stack_a->num && b->num > smallest)
			{
				smallest = b->num;
				target = b;
			}
			b = b->next;
		}
		// If no valid target is found, assign the largest number in stack B as the target
		if (smallest == LONG_MIN)
			stack_a->target = find_largest(stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}

/*
 * Calculates the movement cost for each node in stack A.
 * The cost is the number of moves needed to bring both the node and its target into position.
 */
static void	set_cost(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (stack_a)
	{
		// The base cost is the node's current position
		stack_a->cost = stack_a->position;
		// If the node is in the lower half, the cost is adjusted to count backwards from the end
		if (!(stack_a->upper_part))
			stack_a->cost = len_a - (stack_a->position);
		// Adds the cost of moving the target node in stack B to its correct position
		if (stack_a->target->upper_part)
			stack_a->cost += stack_a->target->position;
		else
			stack_a->cost += len_b - (stack_a->target->position);
		stack_a = stack_a->next;
	}
}

/*
 * Identifies the node in stack A with the lowest movement cost.
 * Marks this node as the best candidate to be moved next.
 */
static void	set_shortest(t_node *stack)
{
	long	shortest;
	t_node	*node;

	if (!stack)
		return ;
	shortest = LONG_MAX;
	// Iterates through the stack to find the node with the lowest cost
	while (stack)
	{
		if (stack->cost < shortest)
		{
			node = stack;
			shortest = stack->cost;
		}
		stack = stack->next;
	}
	node->shortest = true;
}

/*
 * Prepares stack A for sorting by setting all necessary attributes:
 * - Position of each node
 * - Optimal target in stack B
 * - Movement cost
 * - Best candidate for the next move
 */
void	prepare_a(t_node *stack_a, t_node *stack_b)
{
	set_position(stack_a);
	set_position(stack_b);
	set_target_a(stack_a, stack_b);
	set_cost(stack_a, stack_b);
	set_shortest(stack_a);
}