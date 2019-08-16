/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 23:41:12 by minakim           #+#    #+#             */
/*   Updated: 2018/03/08 19:10:31 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**final;
	int		l;
	int		words;

	l = 0;
	if (s == NULL)
		return (0);
	words = ft_count_words(s, c);
	final = (char **)malloc(sizeof(char*) * (words + 1));
	if (final == NULL)
		return (0);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0' && *s != c)
		{
			final[l] = ft_count_letters(s, c);
			l++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	final[l] = 0;
	return (final);
}
