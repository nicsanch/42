/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:29:00 by nicsanch          #+#    #+#             */
/*   Updated: 2023/09/26 17:32:10 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_stack
{
	long			value;
	int				index;
	int				rank;
	int				rra;
	int				ra;
	int				rrb;
	int				rb;
	int				rr;
	int				rrr;
	int				cost;
	int				flag;
	struct s_stack	*next;

}	t_stack;

/*			STACK UTILS:	AUXILIARY STACK FUNCTIONS					*/

/**
 * @brief return the amount of elements in a stack.
 * @param head the first node of a stack.
 * @return the size of the stack.
 */
int		ft_stack_size(t_stack *head);

/**
 * @brief adds a node to the end of a stack.
 * 
 * This functions add the node new to the stack lst.
 * @param lst the stack that is gonna get the new node.
 * @param new the new node you wanna add to the stack.
 */
void	ft_stack_add_back(t_stack **lst, t_stack *new);

/**
 * @brief get a "new" node and insert it as first in a stack.
 * @param lst the stack that gets the new node.
 * @param new the new node to put at the begining of the stack.
 */
void	ft_stack_add_front(t_stack **lst, t_stack *new);

/**
 * @brief delete a node from a stack.
 * @param lst the stack that contains the node.
 * @param index the index of the node to delete.
 */
void	ft_stack_delone(t_stack **lst, int index);

/**
 * @brief copy a node from a stack.
 * @param node the node that gets copied.
 * @return the copy of the original node.
 */
t_stack	*ft_stack_copy_node(t_stack *node);

/*		OTHERS		OTHERS FUNCTIONS										*/

/**
 * @brief check if the input comes in one or multiple strings.
 * @param argc pointer to the numbers of strings in the input
 * @param char pointer to the input's strings.
 */
void	ft_take_arguments(int *argc, char ***argv);

/**
 * @brief takes a array of strings and returns its length.
 * @param array array of strings.
 * @return size of the array.
 */
int		ft_bidimstrlen(char **array);

/**
 * @brief takes a list of nodes and free them.
 * @param a the stack that contains all the nodes.
 */
void	ft_free_stacks(t_stack **a);

/*		STACK TEST	FUNCTIONS TO TEST THE  EXECUTION OF THE PROGRAM		*/

/**
 * @brief prints the "value", "rank" and "index" of every node in a stack.
 * @param head first node of the list.
 */
void	ft_print_stack(t_stack *head);

/**
 * @brief prints all the info of all nodes in the stack.
 * @param head first node of the list.
 */
void	ft_print_stack_f(t_stack *node);

/**
 * @brief checks if there are memory leaks at exit of the program.
 */
void	ft_leaks(void);

/*		STACK_INIT	FUNCTIONS TO START THE STACKS AND ITS VALUES		*/

/**
 * @brief creates a new node.
 * @param content pointer to the content inside the node.
 * @return the new node that has been created.
 */
t_stack	*ft_stack_new(void *content);

/**
 * @brief make a stack, and set the index a rank for every nodes.
 * @param a the stack "a" that will get init.
 * @param n the number of nodes from the stack.
 * @param contents the values for the nodes of the stack.
 * @param flag the flag for the format of the input.
 */
void	ft_init(t_stack **a, int n, char **contents);

/**
 * @brief takes all the arguments passed to the program to make a list with them.
 * 
 * This functions makes a list where will be all the values to order.
 * 
 * @param stack the lists where values are going to be linked.
 * @param n number of elements that will be on the list.
 * @param contents the content of each node.
 * @param flag the flag for the input format.
 */
void	ft_init_stack(t_stack **stack, int n, char **contents);

/**
 * @brief get the index for every node in the stack.
 * @param head first element from a stack.
 */
void	ft_start_index(t_stack *head);

/**
 * @brief check if the arguments can avoid the main algorithm to get ordered.
 * @param a the stack that contains all the nodes.
 * @param b the empty stack.
 */
void	ft_special_cases(t_stack **a, t_stack **b);

/*	STACK_RANKS		FUNTIONS RELATED TO SET THE RANKS OF THE NODES		*/

/**
 * @brief find the node with the minimun "value".
 * @param head the first node of the list.
 * @return returns the node with the minimun value found in the stack.
 */
t_stack	*ft_min_value(t_stack *head);

/**
 * @brief set the "rank" for a node that contains the minimun "value".
 * @param head the first node of the list.
 * @param min the minimun "value" without and updated rank in the stack.
 * @param rank the "rank" that will get the node that you have found before.
 */
void	ft_min_rank(t_stack *head, int min, int rank);

/**
 * @brief set the "rank" for every node on the stack.
 * @param head the first node of the list.
 */
void	ft_get_ranks(t_stack *head);

/**
 * @brief in a 3 node stack, updates the min and maximun rank of the stack.
 * @param min pointer that aims to the current min rank.
 * @param b pointer that aims to the current max rank.
 */
void	ft_min_max(t_stack *a, int *min, int *max);

/*			FUNCTIONS TO CALCULATE THE COST OF THE MOVEMENT				*/

/**
 * @brief set the costs of "ra" and "rra" of the node.
 * @param node that will get updated its "ra"and "rra" values.
 * @param size the size of the stack taht contains the node.
 */
void	ft_cost_a(t_stack *node, int size);

/**
 * @brief set the costs of "rb" and "rrb" of the node.
 * @param node that will get updated its "rb" and "rrb" values.
 * @param size the size of the stack taht contains the node.
 */
void	ft_cost_b(t_stack *node, t_stack *b, int size);

/**
 * @brief set the costs of every simple movements of the stack.
 * 
 * every node of "a" will get updated its values of:
 * "ra", "rra", "rb" and "rrb".
 * @param a the "a" stack.
 * @param b the "b" stack.
 */
void	ft_rotations_cost(t_stack **a, t_stack **b);

/**
 * @brief set the costs of every double movements of the stack.
 * 
 * every node of "a" will get updated its values of:
 * "rr", "rrr".
 * @param a the "a" stack.
 * @param b the "b" stack.
 */
void	ft_bilateral_costs(t_stack *node);

/**
 * @brief gets all the costs for every node in a.
 * @param a the stack that will update all the cost for every node.
 * @param b the (already ordered) stack that should receive the node.

 */
void	ft_costs(t_stack **a, t_stack **b);

/*		TARGETS		FUNCTIONS TO FIND A SPECIFIED NODE OR VALUE			*/

/**
 * @brief find the last node of a stack and returns it.
 * @param head the first node of the stack.
 * @return the last node of the stack.
 */
t_stack	*ft_stack_last(t_stack *lst);

/**
 * @brief find the node that should be the first given the rank of the current.
 * @param b the stack is going to receive a new node.
 * @param rank that rank of the node that is going to be pushed.
 * @return the node that should be the first before to push the current node.
 */
t_stack	*ft_perfect_rank(t_stack **b, int rank);

/**
 * @brief like "ft_perfect_rank" but aimed to incremental order.
 * @param b the stack is going to receive a new node.
 * @param rank that rank of the node that is going to be pushed.
 * @return the node that should be the first before to push the current node.
 */
t_stack	*ft_perfect_rank_inc(t_stack **b, int rank);

/**
 * @brief find the cheapest node of a stack a return it.
 * @param a the stack where you look for the node.
 * @return the cheapest node of the stack "a".
 */
t_stack	*ft_cheapest_node(t_stack **a);

/**
 * @brief gets the cheapest cost of a node to node->cost.
 * @param node the node to get its cost.
 */
void	ft_cheapest_cost(t_stack *node);

/*	FLAGS	FUNCTIONS THAT MOVES STACKS ACCORDING TO THE FLAG OF A NODE		*/

/**
 * @brief makes the amount of ra, rb and rr to prepare the stacks for a push.
 * @param a the stack that will send the node.
 * @param b the that will receive the node.
 * @param node the node that is going to be sent.
 */
void	ft_flag_cero(t_stack **a, t_stack **b, t_stack *node);

/**
 * @brief makes the amount of "ra", "rrb" to prepare the stacks for a push.
 * @param a the stack that will send the node.
 * @param b the that will receive the node.
 * @param node the node that is going to be sent.
 */
void	ft_flag_one(t_stack **a, t_stack **b, t_stack *node);

/**
 * @brief makes the amount of rra, rrb and rrr to prepare the stacks for a push.
 * @param a the stack that will send the node.
 * @param b the that will receive the node.
 * @param node the node that is going to be sent.
 */
void	ft_flag_two(t_stack **a, t_stack **b, t_stack *node);

/**
 * @brief makes the amount of "rb" and "rra" to prepare the stacks for a push.
 * @param a the stack that will send the node.
 * @param b the that will receive the node.
 * @param node the node that is going to be sent.
 */
void	ft_flag_three(t_stack **a, t_stack **b, t_stack *node);

/*			MOVEMENTS	COMBINATIONS OF MOVEMENTS					*/

/**
 * @brief move two nodes from "a" to "b" ("pb, pb").
 * @param a the stack a.
 * @param b the stack b.
 */
void	ft_first_movs(t_stack **a, t_stack **b);

/**
 * @brief move "node" to its ordered position moving acord its flag.
 * @param a the stack that will send a node.
 * @param b the stack that will get the node.
 */
void	ft_move_node(t_stack **a, t_stack **b, t_stack *node);

/**
 * @brief rotate (rr or rrr) a stack to order in decrescent order.
 * @param a the "a" stack.
 * @param b the "b" stack (the one that will get ordered).
 */
void	ft_order_b(t_stack **a, t_stack **b);

/**
 * @brief get the cheapest node of a stack and push it.
 * @param a the stack will send every node (always the cheapest each time).
 * @param b the stack that will get filled with the nodes from a.
 */
void	ft_fill_b(t_stack **a, t_stack **b);

/**
 * @brief push every node from one stack to the other.
 * @param a the stack that will get all the nodes.
 * @param b the stack that will send all the nodes.
 */
void	ft_fill_a(t_stack **a, t_stack **b);

/*				SWAP	FUNCTIONS WITH A LOT OF SWAP					*/

/**
 * @brief swap the first two elements from a stack.
 * @param stack the stack to swap.
 */
void	ft_swap_nodes(t_stack **stack);

/**
 * @brief make one "swap" movement and print it.
 * 
 * Depends ont the value of "n" will do one swap movment:
 * -	With "n" == 'a' make one swap a movement (sa).
 * -	With "n" == 'b' make one swap b movement (sb).
 * -	With "n" == 's' make one swap movement in each stack (ss).
 * 
 * @param a the stack a.
 * @param b the stack b.
 * @param n the flag for the movement.
 */
void	ft_swap(t_stack **a, t_stack **b, int n);

/*		ROTATIONS	FUNCTIONS TO ROTATE AND REVERSE ROTATE NODES		*/

/**
 * @brief moves down every node, so last one become the first.
 * @param stack stack that will get reverse rotated.
 */
void	ft_reverse_rotate(t_stack **stack);

/**
 * @brief moves up every node, so first one become the last.
 * @param stack stack that will get rotated.
 */
void	ft_rotate(t_stack **stack);

/**
 * @brief make one "rotation" movement and print it.
 * 
 * Depends ont the value of "n" will do one swap movment:
 * -	With "n" == 'a' make one rotation a movement (ra).
 * -	With "n" == 'b' make one rotation b movement (rb).
 * -	With "n" == 'r' make one rotation movement in each stack(rr).
 * 
 * @param a the stack a.
 * @param b the stack b.
 * @param n the flag for the movement.
 */
void	ft_rot(t_stack **a, t_stack **b, int n);

/**
 * @brief make one "reverse rotation" movement (rr) and print it.
 * 
 * Depends ont the value of "n" will do one swap movment:
 * -	With "n" == 'a' make one reverse rotation a movement (rra).
 * -	With "n" == 'b' make one reverse rotation b movement (rrb).
 * -	With "n" == 'r' make one rr movement in each stack(rrr).
 * 
 * @param a the stack a.
 * @param b the stack b.
 * @param n the flag for the movement.
 */
void	ft_revrot(t_stack **a, t_stack **b, int n);

/*				PUSH	FUNCTIONS TO DO PUSH MOVEMENTS				*/

/**
 * @brief move first node from one stack to the top of other one.
 * @param a the stack that will send the head of the stack.
 * @param b the stack that will get the node as first of the stack.
 */
void	ft_push_node(t_stack **a, t_stack **b);

/**
 * @brief make one "push" movement and print it.
 * 
 * Depends ont the value of "n" will do one push movment:
 * -	With "n" == 'a' make one push a movement (pa).
 * -	With "n" == 'b' make one push b movement (pb).
 * 
 * @param a the stack a.
 * @param b the stack b.
 * @param n the flag for the movement.
 */
void	ft_push(t_stack **a, t_stack **b, int n);

/*		SPECIAL_CASES	CASES WHERE IS NO NEED TO USE MAIN ALGORITHM	*/

/**
 * @brief checks if there are any duplicated values in the stack.
 * @param a the stack to check the values of all the nodes.
 */
void	ft_check_duplicateds(t_stack *a);

/**
 * @brief checks if values are already ordered and if so, exit the program.
 * @param a the stack that contains the nodes.
 */
void	ft_already_ordered(t_stack *a);

/**
 * @brief orders three elements in ascendent way.
 * @param a the stack that contains the nodes.
 * @param b the auxiliar stack.
 * @param flag 'a' increscent order | 'b' decrecent order.
 */
void	ft_order_two(t_stack **a, t_stack **b, int flag);

/**
 * @brief orders three elements of "a" stack in ascendent way.
 * @param a the stack that contains the nodes.
 * @param b the auxiliar stack.
 */
void	ft_order_three(t_stack **a, t_stack **b);

/**
 * @brief orders four elements of "a" stack in ascendent way.
 * @param a the stack that contains the nodes.
 * @param b the auxiliar stack.
 */
void	ft_order_four(t_stack **a, t_stack **b);

/*	FIVE	FUNCTIONS USED TO ORDER FIVE ELEMENT STACK (ASCENDING ORDER)*/

/**
 * @brief orders five elements of "a" stack in ascendent way.
 * @param a the stack that contains the nodes.
 * @param b the auxiliar stack.
 */
void	ft_order_five(t_stack **a, t_stack **b);

/**
 * @brief gets all the costs to get an ascending order for every node in "a".
 * @param a the stack that will update all the cost for every node.
 * @param b the (already ordered) stack that should receive the node.

 */
void	ft_costs_inc(t_stack **a, t_stack **b);

/**
 * @brief set the costs of every simple movements of the stack(ascending order).
 * 
 * every node of "a" will get updated its values of:
 * "ra", "rra", "rb" and "rrb".
 * @param a the "a" stack.
 * @param b the "b" stack.
 */
void	ft_rotations_cost_inc(t_stack **a, t_stack **b);

/**
 * @brief rotates the stack a(ra or rra) to get it ordered.
 * @param a the "a" stack.
 * @param b the "b" stack.
 */
void	ft_order_a(t_stack **a, t_stack **b);

/*FIVE_FLAGS FUNCTIONS THAT APLLIES THE MOVEMENT TO ORDER NODES(ASCENDING)	*/

/**
 * @brief move "node" to its ordered position moving acord its flag(ascending).
 * @param a the stack that will send a node.
 * @param b the stack that will get the node.
 */
void	ft_move_node_f(t_stack **a, t_stack **b, t_stack *node);

/**
 * @brief makes the amount of rb, ra and rr to prepare the stacks for a push.
 * @param a the stack that will send the node.
 * @param b the that will receive the node.
 * @param node the node that is going to be sent.
 */
void	ft_flag_cero_f(t_stack **a, t_stack **b, t_stack *node);

/**
 * @brief makes the amount of "rb", "rra" to prepare the stacks for a push.
 * @param a the stack that will send the node.
 * @param b the that will receive the node.
 * @param node the node that is going to be sent.
 */
void	ft_flag_one_f(t_stack **a, t_stack **b, t_stack *node);

/**
 * @brief makes the amount of rra, rrb and rrr to prepare the stacks for a push.
 * @param a the stack that will send the node.
 * @param b the that will receive the node.
 * @param node the node that is going to be sent.
 */
void	ft_flag_two_f(t_stack **a, t_stack **b, t_stack *node);

/**
 * @brief makes the amount of "ra" and "rrb" to prepare the stacks for a push.
 * @param a the stack that will send the node.
 * @param b the that will receive the node.
 * @param node the node that is going to be sent.
 */
void	ft_flag_three_f(t_stack **a, t_stack **b, t_stack *node);

#endif
