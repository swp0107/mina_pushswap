/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:44:27 by minakim           #+#    #+#             */
/*   Updated: 2019/06/01 16:44:36 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(uintmax_t nb, uintmax_t base_nb)
{
	char	*result;
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (base_nb < 2 || 16 < base_nb)
		return (NULL);
	result = malloc(sizeof(char) * 35);
	while (base_nb <= nb)
	{
		result[i++] = base[nb % base_nb];
		nb = nb / base_nb;
	}
	if (base_nb > nb)
		result[i++] = base[nb];
	result[i] = '\0';
	ft_strrev(result);
	return (result);
}
