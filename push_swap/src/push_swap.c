/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:32:07 by minakim           #+#    #+#             */
/*   Updated: 2019/08/16 12:56:42 by thomkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_sorted(t_stack *a)
{
	t_node	*tmp;

	tmp = a->top;
	while(tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (1);
			tmp = tmp->next;
	}
	return (0);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (check_nbr(a) < 3)
		sorting_0(a);
	else if (check_nbr(a) == 3)
		sorting_1(a);
	else if (check_nbr(a) > 3 && check_nbr(a) <= 5)
		sorting_3(a, b);
	else if (check_nbr(a) > 5)
		sorting_2(a, b);
    free(a);
    free(b);
}
