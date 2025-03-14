
#include "../include/push_swap.h"

/**
 * The main function for the push_swap program.
 * 
 * This function initializes the stacks, processes the input arguments, 
 * populates the stack with numbers, and sorts them using the appropriate sorting algorithm.
 *
 * @param argc The number of arguments passed to the program.
 * @param argv The array of arguments (numbers to be sorted).
 * @return 0 on successful execution.
 */
int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;

	// If there are no arguments or an empty argument is passed, exit the program.
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);

	// If a single string argument is passed, split it into separate numbers.
	else if (argc == 2)
		argv = push_split(argv[1], ' ');

	// Populate stack A with numbers from the arguments.
	populate_stack(&a, argv + 1, argc == 2);

	// If the stack is not already sorted, determine the appropriate sorting strategy.
	if (!stack_done(a))
	{
		// If there are only 2 numbers, swap them if necessary.
		if (ft_lstsize(a) == 2)
			sa(&a);
		// If there are only 3 numbers, use a simple sorting algorithm.
		else if (ft_lstsize(a) == 3)
			small_sort(&a);
		// Otherwise, use the full sorting algorithm for larger stacks.
		else
			full_sort(&a, &b);
	}
	// Free allocated memory for stack A before exiting.
	free_nodes(&a);
	return (0);
}	