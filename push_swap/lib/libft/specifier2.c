/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:21:35 by minakim           #+#    #+#             */
/*   Updated: 2019/06/01 16:21:40 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*format_o(t_args *format, va_list arg)
{
	uintmax_t	digit;
	char		*ascii;
	int			hash_zero;

	digit = get_u_number(format, arg);
	ascii = ft_itoa_base(digit, 8);
	hash_zero = (format->hash) ? 1 : 0;
	if (format->precis_dot == 1 && format->precis == 0 && !digit)
	{
		if (format->hash == 1)
			ascii = ft_strdup("0");
		else
			ascii = ft_strdup("");
	}
	if (format->precis)
		ascii = to_right(ascii, format->precis - hash_zero, '0');
	if (format->zero == 1 && format->minus == 0)
		ascii = to_right(ascii, format->width, '0');
	if (format->hash == 1 && digit)
		ascii = ft_strjoin_mod("0", &ascii);
	if (format->minus == 1)
		ascii = to_left(ascii, format->width, ' ');
	else
		ascii = to_right(ascii, format->width, ' ');
	return (ascii);
}

char	*u_with_flag(t_args *format, char *ascii)
{
	if (format->precis_dot == 1)
	{
		if (format->minus == 1)
			ascii = to_right(ascii, format->precis, '0');
		else
			ascii = to_right(ascii, format->precis, '0');
	}
	if (format->width)
	{
		if (format->minus == 1)
			ascii = to_left(ascii, format->width, ' ');
		else if (format->zero == 1)
			ascii = to_right(ascii, format->width, '0');
		else
			ascii = to_right(ascii, format->width, ' ');
	}
	else
		return (ascii);
	return (ascii);
}

char	*format_u(t_args *format, va_list arg)
{
	uintmax_t	digit;
	char		*ascii;

	digit = get_u_number(format, arg);
	ascii = ft_itoa_base(digit, 10);
	ascii = u_with_flag(format, ascii);
	return (ascii);
}

char	*format_x(t_args *format, va_list arg)
{
	uintmax_t	digit;
	char		*ascii;
	int			hash_zerox;

	digit = get_u_number(format, arg);
	ascii = ft_itoa_base(digit, 16);
	if (format->precis_dot == 1 && format->precis == 0 && !digit)
		ascii = ft_strdup("");
	hash_zerox = (format->hash == 1) ? 2 : 0;
	if (format->minus == 1)
		ascii = to_left(ascii, format->width - hash_zerox, ' ');
	else if (format->zero == 1)
		ascii = to_right(ascii, format->width - hash_zerox, '0');
	if (format->hash == 1 && digit)
		ascii = ((format->conversion == 'x') ? ft_strjoin_mod("0x", &ascii)
				: ft_strjoin_mod("0X", &ascii));
	if (format->minus == 0 && format->zero == 0)
		ascii = to_right(ascii, format->width, ' ');
	if (format->conversion == 'X')
		ft_strupper(ascii);
	return (ascii);
}
