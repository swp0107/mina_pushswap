/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:33:06 by minakim           #+#    #+#             */
/*   Updated: 2019/06/26 00:52:34 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack)
{
	t_node	*a;
	t_node	*b;

	if (isEmpty(stack) == 0 && stack->top->next)
	{
		a = stack->top;
		b = stack->top->next;
		a->next = b->next;
		b->next = a;
		stack->top = b;
	}
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	t_node	*a;
	t_node	*b;

	if (isEmpty(stack) == 0 && stack->top->next)
	{
		a = stack->top;
		b = stack->top->next;
		a->next = b->next;
		b->next = a;
		stack->top = b;
	}
	ft_printf("sb\n");
}

void	ss(t_stack *stack1, t_stack *stack2)
{
	sa(stack1);
	sb(stack2);
	ft_printf("ss\n");
}

void	pa(t_stack *stack1, t_stack *stack2)
{
	int	tmp;

	if (isEmpty(stack2) == 1)
		return ;
	tmp = pop(stack2);
	push(stack1, tmp);
	ft_printf("pa\n");
}

void	pb(t_stack *stack1, t_stack *stack2)
{
	int	tmp;

	if (isEmpty(stack1) == 1)
		return ;
	tmp = pop(stack1);
	push(stack2, tmp);
	ft_printf("pb\n");
}

void	ra(t_stack *stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (isEmpty(stack) == 1 || !stack->top->next)
		return ;
	tmp1 = stack->top;
	tmp2 = stack->top;
	stack->top = stack->top->next;
	while (tmp1->next)
	{
		tmp1 = tmp1->next;
	}
	tmp1->next = tmp2;
	tmp2->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (isEmpty(stack) == 1 || !stack->top->next)
		return ;
	tmp1 = stack->top;
	tmp2 = stack->top;
	stack->top = stack->top->next; /*복습*/
	while (tmp1->next)
	{
		tmp1 = tmp1->next;
	}
	tmp1->next = tmp2;
	tmp2->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}

void rra(t_stack *stack)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	if(isEmpty(stack) == 1 || !stack->top->next)
		return ;
	a = stack->top;
	b = stack->top;
	c = stack->top;
	while(b->next->next)
	{
		b = b->next;
	}
	c = b->next;
	c->next = a;
	b->next = NULL;
	stack->top = c;
	ft_printf("rra\n");
}

void rrb(t_stack *stack)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	if(isEmpty(stack) == 1 || !stack->top->next)
		return ;
	a = stack->top;
	b = stack->top;
	c = stack->top;
	while(b->next->next)
	{
		b = b->next;
	}
	c = b->next;
	c->next = a;
	b->next = NULL;
	stack->top = c;
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
