
#include "../include/push_swap.h"

/*
 * Validates whether a given argument is a valid integer representation.
 * - Must start with a digit, '+' or '-'.
 * - If it starts with '+' or '-', it must be followed by at least one digit.
 * - The remaining characters must be digits only.
 */
static bool	check_args(char *arg)
{
	if (!(*arg == '+' || *arg == '-' || (*arg >= '0' && *arg <= '9')))
		return (false);
	if ((*arg == '+' || *arg == '-') && (!(arg[1] >= '0' && arg[1] <= '9')))
		return (false);
	while (*++arg)
		if (!(*arg >= '0' && *arg <= '9'))
			return (false);
	return (true);
}

/*
 * Checks for duplicate numbers in the stack.
 * - If the stack is empty, returns true (no duplicates).
 * - Iterates through the stack to verify if the number already exists.
 */
static bool	check_dup(t_node *stack, int num)
{
	if (!stack)
		return (true);
	while (stack)
	{
		if (stack->num == num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

/*
 * Adds a new node containing 'n' to the end of the stack.
 * - Allocates memory for a new node and initializes its values.
 * - If the stack is empty, the new node becomes the first element.
 * - Otherwise, it is appended to the end of the list.
 */
static void	add_node(t_node **stack, int n)
{
	t_node	*new_node;
	t_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->num = n;
	new_node->shortest = false;
	// If the stack is empty, the new node is the first element
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = ft_lstlast(*stack);
		new_node->prev = last_node;
		last_node->next = new_node;
	}
}

/*
 * Handles errors by freeing allocated memory and printing an error message.
 * - If 'array' is true, it also frees the argument matrix.
 * - Exits the program after displaying "Error".
 */
static void	error_handler(t_node **stack, char **ptr, bool array)
{
	free_nodes(stack);
	if (array)
		free_matrix(ptr);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

/*
 * Populates the stack with integers from the argument list.
 * - Validates each argument using check_args().
 * - Converts the argument to a long integer and checks for overflow.
 * - Ensures no duplicate numbers exist using check_dup().
 * - Adds the valid number to the stack.
 */
void	populate_stack(t_node **stack, char **ptr, bool	array)
{
	long	n;
	int		i;

	i = 0;
	while (ptr[i])
	{
		if (!check_args(ptr[i]))
			error_handler(stack, ptr, array);
		n = ft_atol(ptr[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_handler(stack, ptr, array);
		if (!check_dup(*stack, (int)n))
			error_handler(stack, ptr, array);
		add_node(stack, (int)n);
		i++;
	}
	if (array)
		free_matrix(ptr);
}