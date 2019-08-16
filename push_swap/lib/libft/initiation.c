/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:20:19 by minakim           #+#    #+#             */
/*   Updated: 2019/06/01 16:20:24 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_args		*initialization(void)
{
	t_args	*format;

	format = (t_args*)malloc(sizeof(t_args));
	format->space = 0;
	format->zero = 0;
	format->minus = 0;
	format->plus = 0;
	format->hash = 0;
	format->width = 0;
	format->count = 0;
	format->precis_dot = 0;
	format->precis = 0;
	format->conversion = '\0';
	format->flag = 0;
	return (format);
}

intmax_t	get_number(t_args *format, va_list arg)
{
	intmax_t	digit;

	if (format->conversion != 'D' && format->flag == 1)
		digit = (short int)va_arg(arg, int);
	else if (format->flag == 2)
		digit = (char)va_arg(arg, int);
	else if (format->conversion == 'D' || format->flag == 3)
		digit = va_arg(arg, long);
	else if (format->flag == 4)
		digit = va_arg(arg, long long);
	else if (format->flag == 5)
		digit = va_arg(arg, intmax_t);
	else if (format->flag == 6)
		digit = va_arg(arg, size_t);
	else
		digit = va_arg(arg, int);
	return (digit);
}

uintmax_t	get_u_number(t_args *format, va_list arg)
{
	uintmax_t	digit;

	if (format->flag == 1 && format->conversion != 'U' &&
			format->conversion != 'O')
		digit = (unsigned short)va_arg(arg, int);
	else if (format->flag == 2)
		digit = (unsigned char)va_arg(arg, int);
	else if (format->conversion == 'O' || format->conversion == 'U' ||
			format->flag == 3)
		digit = va_arg(arg, unsigned long);
	else if (format->flag == 4)
		digit = va_arg(arg, unsigned long long);
	else if (format->flag == 5)
		digit = va_arg(arg, uintmax_t);
	else if (format->flag == 6)
		digit = va_arg(arg, size_t);
	else
		digit = va_arg(arg, unsigned int);
	return (digit);
}
