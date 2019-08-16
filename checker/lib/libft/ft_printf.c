/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:19:57 by minakim           #+#    #+#             */
/*   Updated: 2019/06/01 16:20:04 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		parsing(va_list arg, char **str, int count)
{
	char	*argstr;
	t_args	*format;

	argstr = *str;
	format = initialization();
	if (argstr[0] == '\0')
		return (0);
	while (*argstr)
	{
		argstr = *check_flag(&argstr, format);
		argstr = *check_width(&argstr, format, arg);
		argstr = *check_precision(&argstr, format, arg);
		argstr = *check_extra(&argstr, format);
		argstr = *check_conversion(&argstr, format);
		count = print_format(format, arg, count);
		if (format->count > 0)
			count += format->count;
		*str = argstr;
		break ;
	}
	free(format);
	return (count);
}

int		ft_printf(char *string, ...)
{
	va_list		arg;
	int			count;
	char		*str;

	count = 0;
	va_start(arg, string);
	str = string;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count = parsing(arg, &str, count);
		}
		else
		{
			ft_putchar(*str);
			str++;
			count++;
		}
	}
	va_end(arg);
	return (count);
}
