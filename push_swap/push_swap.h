/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:46:40 by lofiorin          #+#    #+#             */
/*   Updated: 2024/04/25 09:49:34 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;
	int				cost;
	bool			above_m;
	bool			cheap;
}	t_node;

//A function that handles the case of all the nubers passed in one argument.
char	**check_arg_num(int ac, char **av);

//Utility functions for double linked lists.
t_node	*ft_dllstnew(int content);
t_node	*ft_dllstlast(t_node *lst);
void	ft_dllstadd_back(t_node **lst, t_node *new);
int		ft_dllstsize(t_node *lst);
t_node	*min_node(t_node *node);
t_node	*max_node(t_node *node);
t_node	*get_cheap(t_node *node);
void	*free_list(t_node **node);
void	min_up(t_node **a);

//A function that checks if a number is already in the stack.
int		ft_list_check(int num, t_node *a);

//A function that initializes the a stack with the arguments passed.
t_node	*stack_init(char **args, t_node *a);

//A function that checks if the stack is sorted.
int		ft_list_sorted(t_node *a);

//The functions used to sort the stacks
void	push(t_node **dest, t_node **source, char stack);
void	r(t_node **node, char stack, bool print);
void	rs(t_node **a, t_node **b, bool print);
void	rr(t_node **node, char stack, bool print);
void	rrs(t_node **a, t_node **b, bool print);
void	s(t_node **node, char stack, bool print);
void	ss(t_node **a, t_node **b, bool print);

//A function used to sort three nodes.
void	minisort(t_node **node, char stack);

//A function that sets the indexes in a stack.
void	set_index(t_node *node);

//A function that initializes both stacks to be sorted.
void	sort_init(t_node *a, t_node *b);

//A function that prepeares the stack to push a node.
void	push_init(t_node **node, t_node *top, char stack);

//A function thet sorts the stacks.
void	sort(t_node **a, t_node **b);
#endif