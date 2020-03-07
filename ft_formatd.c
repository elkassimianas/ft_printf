/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 10:45:24 by ael-kass          #+#    #+#             */
/*   Updated: 2020/01/09 11:13:41 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_formatd(const char **format, int nbatoi, va_list args)
{
	int				nbargs;
	int				nbpoint;
	char			*stritoa;

	nbpoint = 1;
	if (**format != '%')
		nbargs = va_arg(args, int);
	if (**format == 'x' || **format == 'X')
		stritoa = casdex(nbargs, format);
	else if (**format != '%')
		stritoa = ft_itoa(format, nbargs);
	else
	{
		if ((stritoa = (char *)malloc(2)) == NULL)
			return (-1);
		stritoa[0] = '%';
		stritoa[1] = '\0';
	}
	if (nbatoi > 0)
		ft_positive(&stritoa, nbatoi, nbpoint);
	if (nbatoi < 0)
		ft_negative(&stritoa, nbatoi, nbpoint);
	nbargs = ft_putstr(stritoa);
	ft_free(&stritoa);
	return (nbargs);
}

int		ft_formatd1(const char **format, int nbatoi, va_list args)
{
	int				nbargs;
	char			*stritoa;

	if (**format != '%')
		nbargs = va_arg(args, int);
	if (**format == 'x' || **format == 'X')
		stritoa = casdex(nbargs, format);
	else if (**format != '%')
		stritoa = ft_itoa(format, nbargs);
	else
	{
		if ((stritoa = (char *)malloc(2)) == NULL)
			return (-1);
		stritoa[0] = '%';
		stritoa[1] = '\0';
	}
	if (nbargs >= 0 || **format == 'u' || **format == 'x' || **format == 'X'
	|| **format == '%')
		ft_positivecas0(&stritoa, nbatoi);
	else
		ft_negativecas0(&stritoa, nbatoi);
	nbargs = ft_putstr(stritoa);
	ft_free(&stritoa);
	return (nbargs);
}

int		ft_formatd2(const char **format, int nbatoi, int nbpoint, va_list args)
{
	int				nbargs;
	char			*stritoa;

	if (**format != '%')
		nbargs = va_arg(args, int);
	if (**format == '%')
	{
		nbpoint = 0;
		nbargs = 1;
	}
	if (nbargs == 0 && nbatoi == 0 && nbpoint == 0)
		return (nbargs);
	stritoa = helpformatd2(nbargs, format);
	if (nbpoint > 0)
	{
		if (nbargs >= 0 || **format == 'u' || **format == 'x'
		|| **format == 'X')
			ft_positivecas0(&stritoa, nbpoint);
		else
		{
			nbpoint = nbpoint + 1;
			ft_negativecas0(&stritoa, nbpoint);
		}
	}
	return (helpformad02(nbatoi, stritoa, nbpoint, nbargs));
}

int		helpformad02(int nbatoi, char *stritoa, int nbpoint, int nbargs)
{
	if (nbatoi > 0)
		ft_positive(&stritoa, nbatoi, nbpoint);
	if (nbatoi < 0)
		ft_negative(&stritoa, nbatoi, nbpoint);
	nbargs = ft_putstr(stritoa);
	ft_free(&stritoa);
	return (nbargs);
}

char	*helpformatd2(int nbargs, const char **format)
{
	char	*stritoa;

	if (**format == 'x' || **format == 'X')
		stritoa = casdex(nbargs, format);
	else if (**format != '%')
		stritoa = ft_itoa(format, nbargs);
	else
	{
		if ((stritoa = (char *)malloc(2)) == NULL)
			return (NULL);
		stritoa[0] = '%';
		stritoa[1] = '\0';
	}
	return (stritoa);
}
