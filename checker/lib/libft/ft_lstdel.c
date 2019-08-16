/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 23:54:53 by minakim           #+#    #+#             */
/*   Updated: 2018/03/12 21:22:41 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*fresh;
	t_list	*tmp;

	if (alst != NULL)
	{
		fresh = *alst;
		while (fresh != NULL)
		{
			tmp = fresh->next;
			del(fresh->content, fresh->content_size);
			free(fresh);
			fresh = tmp;
		}
		*alst = NULL;
	}
}
