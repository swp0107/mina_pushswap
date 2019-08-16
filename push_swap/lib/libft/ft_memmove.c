/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 20:03:42 by minakim           #+#    #+#             */
/*   Updated: 2018/03/06 22:19:55 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ds;
	char	*sr;

	i = 0;
	ds = (char*)dst;
	sr = (char*)src;
	if (src >= dst)
	{
		while (i < len)
		{
			ds[i] = sr[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			ds[len - 1] = sr[len - 1];
			len--;
		}
	}
	return (dst);
}
