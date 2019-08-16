/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:10:25 by minakim           #+#    #+#             */
/*   Updated: 2019/08/16 13:01:59 by thomkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sorting_0(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sorting_1(t_stack *a)
{
	t_struct	*nbr;

	nbr = init_nbr();
	check_value(a, nbr);
	if (a->top->value == nbr->min && a->top->next->value == nbr->max)
	{
		sa(a);
		ra(a);
	}
	else if (a->top->value == nbr->mid)
	{
		if (a->top->next->value == nbr->min)
			sa(a);
		else
			rra(a);
	}
	else if  (a->top->value == nbr->max)
	{
		if (a->top->next->value == nbr->mid)
		{
			sa(a);
			rra(a);
		}
		else
			ra(a);
	}
    free(nbr);
}

void	sorting_2(t_stack *a, t_stack *b)
{
	while (a->top)
	{
		int	min = find_min(a);
		int	min_index = find_index(a, min);
		if (min_index < (check_nbr(a) / 2 + 1))
		{
			while (min_index > 1)
			{
				ra(a);
				min_index--;
			}
		}
		else
		{
			while (min_index != check_nbr(a) + 1)
			{
				rra(a);
				min_index++;
			}
		}
		pb(a, b);
	}
	while (!isEmpty(b))
		pa(a, b);
}

void	sorting_3(t_stack*a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	sorting_1(a);
	while (!isEmpty(b))
	{
		if (b->top->value <= a->top->value)
			pa(a, b);
		else if (b->top->value >= find_max(a))
		{
			pa(a, b);
			ra(a);
		}
		else if (b->top->value < find_max(a) && b->top->value >= a->top->next->value)
		{
			if (check_nbr(a) == 3) {
				pa(a, b);
				rra(a);
				sa(a);
				ra(a);
				ra(a);
			}
			else {
				if (b->top->value >= a->top->next->next->value) {
					pa(a, b);
					sa(a);
					ra(a);
					ra(a);
				}
				else {
					rra(a);
					rra(a);
					pa(a, b);
					ra(a);
					ra(a);
					ra(a);
				}
			}
		}
		else if (b->top->value > a->top->value && b->top->value < a->top->next->value) {
			pa(a, b);
			sa(a);
		}
	}
}
/*
   void	sorting_2(t_stack *a, t_stack *b)
   {
//	t_struct	*nbr;

//	nbr = init_nbr();
pb(a, b);
pb(a, b);
ft_printf("pb\n");
ft_printf("pb\n");
sorting_1(a);
while (!isEmpty(b))
{
if (b->top->value <= a->top->value)
{
pa(a, b);
ft_printf("pa\n");
}
else if (b->top->value >= find_max(a))
{
pa(a, b);
ra(a);
ft_printf("pa\n");
ft_printf("ra\n");
}
else if (b->top->value < find_max(a) && b->top->value >= a->top->next->value)
{
if (check_nbr(a) == 3) {
pa(a, b);
rra(a);
sa(a);
ra(a);
ra(a);
ft_printf("pa\n");
ft_printf("rra\n");
ft_printf("sa\n");
ft_printf("ra\n");
ft_printf("ra\n");
}
else {
if (b->top->value > a->top->next->next->value) {
pa(a, b);
sa(a);
ra(a);
ra(a);
ft_printf("pa\n");
ft_printf("sa\n");
ft_printf("ra\n");
ft_printf("ra\n");
}
else {
rra(a);
rra(a);
pa(a, b);
ra(a);
ra(a);
ra(a);
ft_printf("rra\n");
ft_printf("rra\n");
ft_printf("pa\n");
ft_printf("ra\n");
ft_printf("ra\n");
ft_printf("ra\n");
}
}
}
}
}
 */
