/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:21:13 by minakim           #+#    #+#             */
/*   Updated: 2019/06/01 16:21:20 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*format_big_s(t_args *format, va_list arg)
{
	char		*wstr;
	wchar_t		*tmp;
	int			i;
	int			l;

	i = 0;
	tmp = va_arg(arg, void *);
	if (!tmp)
		return (ft_strdup("(null)"));
	l = ft_wstrlen(tmp);
	wstr = malloc(l + 1);
	while (i < l)
	{
		wstr[i] = tmp[i];
		i++;
	}
	wstr[i] = '\0';
	if (format->precis_dot == 1 && format->precis != 0 &&
			format->precis < l)
		wstr = cut_right(wstr, format->precis);
	if (format->minus == 1)
		wstr = to_left(wstr, format->width, ' ');
	else
		wstr = to_right(wstr, format->width, ' ');
	return (wstr);
}

char	*format_s(t_args *format, va_list arg)
{
	char	*str;
	char	*tmp;
	int		i;
	int		l;

	if (format->conversion == 'S' || (format->conversion == 's' &&
				format->flag == 3))
		return (format_big_s(format, arg));
	i = 0;
	tmp = va_arg(arg, char *);
	if (!tmp)
		return (ft_strdup("(null)"));
	str = ft_strdup(tmp);
	l = ft_strlen(str);
	if (format->precis_dot == 1 && format->precis != 0 &&
			format->precis < l)
		str = cut_right(str, format->precis);
	if (format->minus == 1)
		str = to_left(str, format->width, ' ');
	else
		str = to_right(str, format->width, ' ');
	return (str);
}

char	*format_d(t_args *format, va_list arg)
{
	intmax_t	digit;
	char		*ascii;
	int			sign;

	digit = get_number(format, arg);
	ascii = ft_itoa(digit);
	sign = (digit < 0 || format->plus || format->space) ? 1 : 0;
	ascii = (digit < 0) ? cut_left(ascii, 1) : ascii;
	ascii = (format->precis > 0) ? to_right(ascii, format->precis, '0') : ascii;
	if (format->minus == 0 && format->zero == 1 && format->precis_dot == 0)
		ascii = to_right(ascii, format->width - sign, '0');
	if (digit < 0)
		ascii = ft_strjoin_mod("-", &ascii);
	else if (format->plus == 1 && digit >= 0)
		ascii = ft_strjoin_mod("+", &ascii);
	else if (format->space == 1 && digit >= 0)
		ascii = ft_strjoin_mod(" ", &ascii);
	if (format->precis_dot == 1 && format->precis == 0 && digit == 0)
		ascii = ft_strdup("");
	if (format->minus == 1)
		ascii = to_left(ascii, format->width, ' ');
	else
		ascii = to_right(ascii, format->width, ' ');
	return (ascii);
}

char	*format_p(t_args *format, va_list arg)
{
	uintmax_t	argptr;
	char		*ascii;

	argptr = (uintmax_t)va_arg(arg, void *);
	ascii = ft_itoa_base(argptr, 16);
	ascii = ft_strjoin_mod("0x", &ascii);
	if (format->minus == 1)
		ascii = to_left(ascii, format->width, ' ');
	else
		ascii = to_right(ascii, format->width, ' ');
	return (ascii);
}
