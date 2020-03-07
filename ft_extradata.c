/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extradata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:37:34 by ael-kass          #+#    #+#             */
/*   Updated: 2020/01/08 11:02:33 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		helpextra(const char **format, va_list args)
{
	int		nbwidth;

	while (**format != 48 && **format != 'd' && **format != '.')
	{
		if (**format == 'i' || **format == 'u' || **format == 'x'
		|| **format == 'X' || **format == '%')
			break ;
		nbwidth = ft_atoi(format, args);
		if (**format == 'p' || **format == 's' || **format == 'c')
			break ;
		if (**format == '.')
		{
			(*format)++;
			nbwidth = help01(format, args, nbwidth);
			return (nbwidth);
		}
		if (nbwidth < 0)
			return (ft_formatd(format, nbwidth, args));
		if (nbwidth != 0)
			return (ft_formatd1(format, nbwidth, args));
		(*format)++;
	}
	return (-1);
}

int		helpextra1(const char **format, va_list args)
{
	int				len;
	int				nbwidth;
	int				nbpre;

	len = 0;
	nbpre = 0;
	nbwidth = ft_atoi(format, args);
	if (**format == '.')
		return (help02(format, args, nbwidth));
	if (**format == 'p')
		len = ft_formatdep(format, nbwidth, args);
	if (**format == 's')
		len = formatdes(nbpre, nbwidth, args);
	if (**format == 'c')
		len = ft_formatdec(nbwidth, args);
	if (**format == 'd' || **format == 'i' || **format == 'u'
	|| **format == 'x' || **format == 'X' || **format == '%')
		len = ft_formatd(format, nbwidth, args);
	return (len);
}

int		ft_extradata(const char **format, va_list args)
{
	int		len;

	len = 0;
	while (**format == 48)
	{
		(*format)++;
		len = helpextra(format, args);
		if (len != -1)
			return (len);
	}
	return (helpextra1(format, args));
}

int		help01(const char **format, va_list args, int nbwidth)
{
	int		nbpre;

	nbpre = ft_atoi(format, args);
	if (nbwidth < 0)
		return (ft_formatd2(format, nbwidth, nbpre, args));
	if (**format == '%' && nbwidth > 0)
		return (ft_formatd1(format, nbwidth, args));
	if (nbpre < 0 && nbwidth > 0)
		return (ft_formatd1(format, nbwidth, args));
	return (ft_formatd2(format, nbwidth, nbpre, args));
}

int		help02(const char **format, va_list args, int nbwidth)
{
	int		nbpre;
	int		len;

	len = 0;
	(*format)++;
	nbpre = ft_atoi(format, args);
	if (**format == 's' && nbpre == 0)
		nbpre = -1;
	if (**format == 'p')
		len = ft_formatdep(format, nbwidth, args);
	if (**format == 's')
		len = formatdes(nbpre, nbwidth, args);
	if (**format == 'c')
		len = ft_formatdec(nbwidth, args);
	if (**format != 'p' && **format != 's' && **format != 'c')
		len = ft_formatd2(format, nbwidth, nbpre, args);
	return (len);
}
