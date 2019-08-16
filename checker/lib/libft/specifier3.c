/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:21:53 by minakim           #+#    #+#             */
/*   Updated: 2019/06/01 16:21:58 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		format_c_2(t_args *format)
{
	char	c;

	c = 0;
	if (format->minus == 0)
	{
		while (--format->width > 0)
		{
			ft_putchar(' ');
			format->count += 1;
		}
		write(1, &c, 1);
		format->count += 1;
	}
	else if (format->minus == 0)
	{
		write(1, &c, 1);
		format->count += 1;
		while (--format->width > 0)
		{
			ft_putchar(' ');
			format->count += 1;
		}
	}
	return (1);
}

char	*format_c(t_args *format, va_list arg)
{
	char	*str;
	int		c;

	str = ft_strnew(1);
	if (format->conversion == 'C' || format->flag == 3 ||
			format->flag == 4)
		c = va_arg(arg, wchar_t);
	else
		c = (unsigned char)va_arg(arg, void *);
	if (!c)
	{
		format_c_2(format);
		return (str);
	}
	str[0] = c;
	if (format->minus == 1 && format->width > 0)
		str = to_left(str, format->width, ' ');
	else if (format->width > 0)
		str = to_right(str, format->width, ' ');
	return (str);
}

char	*format_percent(t_args *format)
{
	char	*str;

	str = ft_strdup("%");
	if (format->minus == 1)
		str = to_left(str, format->width, ' ');
	else if (format->zero == 1)
		str = to_right(str, format->width, '0');
	else
		str = to_right(str, format->width, ' ');
	return (str);
}
