/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 19:03:50 by minakim           #+#    #+#             */
/*   Updated: 2018/03/11 22:28:15 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ds;
	unsigned char	*sr;

	i = 0;
	ds = (unsigned char*)dst;
	sr = (unsigned char*)src;
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (dst);
}
