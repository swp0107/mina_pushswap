/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 01:00:31 by minakim           #+#    #+#             */
/*   Updated: 2018/03/11 23:47:15 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char*)malloc(sizeof(char) * len + 1);
	if (str != NULL && s != NULL)
	{
		while (i < len)
		{
			str[i] = s[start];
			i++;
			start++;
		}
	}
	else
		return (NULL);
	str[i] = '\0';
	return (str);
}
