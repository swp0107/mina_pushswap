/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:22:12 by minakim           #+#    #+#             */
/*   Updated: 2019/06/01 16:22:21 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*cut_left(char *str, int n)
{
	char	*tmp;
	char	*tmp2;
	int		i;
	int		l;
	int		j;

	i = 0;
	j = 0;
	tmp = str;
	l = ft_strlen(str);
	tmp2 = (char *)malloc(sizeof(char) * l + 1);
	while (i < n)
		i++;
	while (i < l)
	{
		tmp2[j] = tmp[i];
		i++;
		j++;
	}
	tmp2[j] = '\0';
	free(tmp);
	return (tmp2);
}

char	*cut_right(char *str, int n)
{
	char	*tmp;
	char	*newstr;
	int		i;
	int		l;

	i = 0;
	tmp = str;
	l = ft_strlen(str);
	newstr = (char *)malloc(sizeof(char) * l + 1);
	while (i < n)
	{
		newstr[i] = tmp[i];
		i++;
	}
	newstr[i] = '\0';
	free(tmp);
	return (newstr);
}

char	*to_left(char *str, int n, char c)
{
	char	*tmp;
	char	*newstr;
	int		i;
	int		l;
	int		j;

	i = 0;
	j = 0;
	tmp = str;
	l = ft_strlen(str);
	if (n <= l)
		return (str);
	newstr = (char *)malloc(sizeof(char) * n + 1);
	while (i < l)
		newstr[i++] = tmp[j++];
	while (i < n)
		newstr[i++] = c;
	newstr[i] = '\0';
	free(tmp);
	return (newstr);
}

char	*to_right(char *str, int n, char c)
{
	char	*tmp;
	char	*newstr;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	tmp = str;
	l = ft_strlen(str);
	if (n <= l)
		return (str);
	newstr = ft_strnew(n);
	while (i < (n - l))
		newstr[i++] = c;
	while (i < n)
		newstr[i++] = tmp[j++];
	newstr[i] = '\0';
	free(tmp);
	return (newstr);
}
