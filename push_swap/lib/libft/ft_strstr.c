/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 22:04:52 by minakim           #+#    #+#             */
/*   Updated: 2018/03/10 16:12:59 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int n;

	i = 0;
	if (*needle == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		n = 0;
		while (needle[n] != '\0' && haystack[i + n] == needle[n])
			n++;
		if (needle[n] == '\0')
			return ((char*)haystack + i);
		i++;
	}
	return (NULL);
}
