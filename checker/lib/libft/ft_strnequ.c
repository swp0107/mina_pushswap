/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 00:35:24 by minakim           #+#    #+#             */
/*   Updated: 2018/03/01 00:35:28 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (a < n)
		{
			if (s1[a] == s2[a])
				b++;
			a++;
		}
		if (a == b)
			return (1);
	}
	return (0);
}
