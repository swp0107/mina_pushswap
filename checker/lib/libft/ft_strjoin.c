/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 01:14:21 by minakim           #+#    #+#             */
/*   Updated: 2018/03/12 00:13:13 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		l;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * l + 1)))
		return (NULL);
	l = 0;
	if (str)
	{
		while (s1[i] != '\0')
		{
			str[l++] = s1[i++];
		}
		i = 0;
		while (s2[i] != '\0')
		{
			str[l++] = s2[i++];
		}
	}
	str[l] = '\0';
	return (str);
}
