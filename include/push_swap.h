
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				num;
	int				position;
	int				cost;
	bool			shortest;
	bool			upper_part;
	struct s_node	*target;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

//push_utils
bool	stack_done(t_node *stack);
t_node	*find_smallest(t_node *stack);
t_node	*find_largest(t_node *stack);
void	free_nodes(t_node **stack);
t_node	*get_shortest(t_node *stack);
void	set_top_a(t_node **stack, t_node *top);
void	set_top_b(t_node **stack, t_node *top);
int		ft_lstsize(t_node *lst);
t_node	*ft_lstlast(t_node *lst);

//populate_stack
void	populate_stack(t_node **stack, char **argv, bool array);

//split
char	**push_split(char *str, char separator);
void	free_matrix(char **argv);

//moves
void	pb(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_b, t_node **stack_a);
void	rra(t_node **stack);
void	rrb(t_node **stack);
void	rrr(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack);
void	rb(t_node **stack);
void	rr(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack);
void	sb(t_node **stack);
void	ss(t_node **stack_a, t_node **stack_b);

//move_utils
void	set_top_a(t_node **stack, t_node *top);
void	set_top_b(t_node **stack, t_node *top);
void	rotate_a_b(t_node **stack_a, t_node **stack_b, t_node *shortest);
void	reverse_a_b(t_node **stack_a, t_node **stack_b, t_node *shortest);

//sorter
void	small_sort(t_node **stack);
void	full_sort(t_node **stack_a, t_node **stack_b);
void	set_position(t_node *stack);
void	prepare_a(t_node *stack_a, t_node *stack_b);
void	prepare_b(t_node *stack_a, t_node *stack_b);

#endif