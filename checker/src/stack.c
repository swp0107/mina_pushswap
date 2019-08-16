/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 23:19:34 by minakim           #+#    #+#             */
/*   Updated: 2019/06/26 00:55:47 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

struct s_stack	*initstack(void)
{
	struct s_stack	*new = malloc(sizeof(struct s_stack));

	new->top = NULL;
	return (new);
}

int	isEmpty(struct s_stack *stack)
{
	if (!stack->top)
		return (1);
	return (0);
}

void	push(struct s_stack *stack, int content)
{
	struct s_node	*new = malloc(sizeof(struct s_node));

	new->value = content;
	new->next = stack->top;
	stack->top = new;
}

int	peek(struct s_stack *stack)
{
	if (isEmpty(stack) == 1)
		return (-1);
	return (stack->top->value);
}

int	pop(struct s_stack *stack)
{
	int	pop;
	struct s_node	*tmp;
	if (isEmpty(stack) == 1)
		return (-1);
	pop = stack->top->value;
	tmp = stack->top;
	stack->top = stack->top->next;
	free(tmp);
	return (pop);
}
