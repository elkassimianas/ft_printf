/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 10:08:27 by ael-kass          #+#    #+#             */
/*   Updated: 2020/01/09 12:22:15 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int			len;
	int			len1;
	va_list		args;
	int			i;

	len = 0;
	len1 = 0;
	i = 0;
	va_start(args, format);
	len = help13(format, args, len1, len);
	va_end(args);
	return (len);
}

int		help13(const char *format, va_list args, int len1, int len)
{
	while (*format != '\0')
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			len++;
		}
		else
		{
			if (*format == '%' && *(format + 1) == '%')
			{
				ft_putchar(*format);
				len++;
			}
			format++;
			if (*format != '%')
				len1 += ft_extradata(&format, args);
		}
		format++;
	}
	return (len + len1);
}
