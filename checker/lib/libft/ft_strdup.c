/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 00:09:34 by minakim           #+#    #+#             */
/*   Updated: 2018/03/11 22:41:35 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		i;
	int		l;

	i = 0;
	l = ft_strlen(s1);
	s = (char*)malloc(sizeof(char) * (l + 1));
	if (s == 0)
		return (s);
	while (i < l)
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
