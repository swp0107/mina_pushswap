/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 21:30:44 by minakim           #+#    #+#             */
/*   Updated: 2018/03/12 21:32:44 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tab;
	int		a;
	int		b;

	if (s == NULL)
		return (NULL);
	a = ft_strlen(s);
	tab = (char*)malloc(sizeof(char) * a + 1);
	if (tab == NULL)
		return (NULL);
	a = 0;
	b = 0;
	while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
		a++;
	while (s[a])
		tab[b++] = s[a++];
	a--;
	while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
	{
		tab[b] = '\0';
		b--;
		a--;
	}
	tab[b] = '\0';
	return (tab);
}
