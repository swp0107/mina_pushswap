/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 23:11:32 by minakim           #+#    #+#             */
/*   Updated: 2019/07/16 16:32:04 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# include <ctype.h>

typedef struct	s_node {
	int	value;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack {
	struct s_node	*top;
}				t_stack;

struct s_stack		*initstack(void);
int					isEmpty(struct s_stack *stack);
void				push(struct s_stack *stack, int content);
int					peek(struct s_stack *stack);
int					pop(struct s_stack *stack);
void				print_stack(struct s_stack *stack);
int					isInt(char *str);

void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				ss(t_stack *stack1, t_stack *stack2);
void				pa(t_stack *stack1, t_stack *stack2);
void				pb(t_stack *stack1, t_stack *stack2);
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rr(t_stack *a, t_stack *b);

void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);

void    sort(t_stack *stack);
#endif
