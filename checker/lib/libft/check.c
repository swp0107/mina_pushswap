/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:19:22 by minakim           #+#    #+#             */
/*   Updated: 2019/06/01 16:19:41 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**check_flag(char **argstr, t_args *format)
{
	while (**argstr == ' ' || **argstr == '0' || **argstr == '-' ||
			**argstr == '+' || **argstr == '#')
	{
		if (**argstr == ' ')
			format->space = 1;
		else if (**argstr == '0' && format->minus != 1)
			format->zero = 1;
		else if (**argstr == '-')
			format->minus = 1;
		else if (**argstr == '-' && format->zero == 1)
			format->zero = 0;
		else if (**argstr == '+')
			format->plus = 1;
		else if (**argstr == '+' && format->space == 1)
			format->space = 0;
		else if (**argstr == '#')
			format->hash = 1;
		(*argstr)++;
	}
	return (argstr);
}

char	**check_width(char **argstr, t_args *format, va_list arg)
{
	if (**argstr != '.')
	{
		if (**argstr == '*')
		{
			format->width = va_arg(arg, int);
			(*argstr)++;
		}
		else
		{
			while (ft_isdigit(**argstr))
			{
				format->width = format->width * 10 + (**argstr - '0');
				(*argstr)++;
			}
			if (**argstr == '+' || **argstr == '-' || **argstr == ' ')
				(*argstr)++;
		}
	}
	return (argstr);
}

char	**check_precision(char **argstr, t_args *format, va_list arg)
{
	while (**argstr == '.')
	{
		format->precis_dot = 1;
		(*argstr)++;
		if (**argstr == '-' || **argstr == ' ' || **argstr == '+')
			(*argstr)++;
		if (**argstr == '*')
		{
			format->precis = va_arg(arg, int);
			(*argstr)++;
		}
		else if (**argstr >= 48 && **argstr <= 57)
		{
			while (ft_isdigit(**argstr))
			{
				format->precis = format->precis * 10 + (**argstr - '0');
				(*argstr)++;
			}
		}
		else
			return (argstr);
	}
	return (argstr);
}

char	**check_extra(char **argstr, t_args *format)
{
	if ((**argstr == 'h' && *(*argstr + 1) == 'h') || (**argstr == 'l'
				&& *(*argstr + 1) == 'l'))
	{
		if (**argstr == 'h')
			format->flag = hh;
		else
			format->flag = ll;
		(*argstr += 2);
	}
	else if (**argstr == 'h' || **argstr == 'l' || **argstr == 'j'
	|| **argstr == 'z')
	{
		if (**argstr == 'h')
			format->flag = h;
		if (**argstr == 'l')
			format->flag = l;
		if (**argstr == 'j')
			format->flag = j;
		if (**argstr == 'z')
			format->flag = z;
		(*argstr)++;
	}
	else
		return (argstr);
	return (argstr);
}

char	**check_conversion(char **argstr, t_args *format)
{
	if (**argstr == 's' || **argstr == 'S' || **argstr == 'p'
			|| **argstr == 'd' || **argstr == 'D' || **argstr ==
			'i' || **argstr == 'o' || **argstr == 'O' || **argstr
			== 'u' || **argstr == 'U' || **argstr == 'x' ||
			**argstr == 'X' || **argstr == 'c' || **argstr == 'C' ||
			**argstr == '%')
	{
		format->conversion = **argstr;
		(*argstr)++;
	}
	else
		(*argstr)++;
	return (argstr);
}
