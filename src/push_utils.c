
#include "../include/push_swap.h"

// Function to check if the stack is sorted in ascending order
bool	stack_done(t_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		// If current node is greater than the next one, stack is not sorted
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

// Function to find the smallest element in the stack
t_node	*find_smallest(t_node *stack)
{
	t_node	*node;
	long	min;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	// Traverse the stack to find the smallest element
	while (stack)
	{
		if (stack->num < min)
		{
			min = stack->num;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

// Function to find the largest element in the stack
t_node	*find_largest(t_node *stack)
{
	t_node	*node;
	long	max;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	// Traverse the stack to find the largest element
	while (stack)
	{
		if (stack->num > max)
		{
			max = stack->num;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

// Function to free all nodes in the stack
void	free_nodes(t_node **stack)
{
	t_node	*temp;
	
	// Traverse the stack and free each node
	while(*stack)
	{
		temp = *stack;
		*stack = temp->next;
		free(temp);
	}
}

// Function to get the node with the shortest cost in the stack
t_node	*get_shortest(t_node *stack)
{
	if (!stack)
		return (NULL);
	// Traverse the stack to find the node with the shortest cost
	while (stack)
	{
		if (stack->shortest)
			return (stack);
		else
			stack = stack->next;
	}
	return (NULL);
}