/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:10:20 by ael-kass          #+#    #+#             */
/*   Updated: 2020/01/11 15:41:54 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_formatdec(int nbwidth, va_list args)
{
	char	strargs;
	int		nbpre;
	char	*stritoa;

	nbpre = 0;
	strargs = va_arg(args, int);
	stritoa = (char *)malloc(2);
	stritoa[0] = strargs;
	stritoa[1] = '\0';
	if (nbwidth == 0)
		nbpre = ft_putchar(stritoa[0]);
	if (nbwidth > 0)
		nbpre = ft_positivedec(&stritoa, nbwidth, nbpre);
	if (nbwidth < 0)
		nbpre = ft_negativedec(&stritoa, nbwidth, nbpre);
	ft_free(&stritoa);
	return (nbpre);
}

int		ft_positivedec(char **stritoa, int nbatoi, int nbpoint)
{
	int			i;

	i = 0;
	if (**stritoa == '\0')
		nbatoi = nbatoi - 1;
	else
		nbatoi = nbatoi - ft_strlen(*stritoa);
	if (nbatoi < 0)
		return (0);
	while (i < nbatoi)
		i = ft_putchar(' ') + i;
	if (nbpoint == 0 && **stritoa == 48)
		i = ft_putchar(' ') + i;
	if (**stritoa == '\0')
		i = ft_putchar('\0') + i;
	else
		i = ft_putstr(*stritoa) + i;
	return (i);
}

int		ft_negativedec(char **stritoa, int nbatoi, int nbpoint)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	nbatoi = -1 * nbatoi;
	if (**stritoa == '\0')
		nbatoi = nbatoi - 1;
	else
		nbatoi = nbatoi - ft_strlen(*stritoa);
	if (nbatoi < 0)
		return (0);
	if (**stritoa != '\0')
		len = ft_putstr(*stritoa);
	else
		len = ft_putchar('\0');
	while (i < nbatoi)
		i = ft_putchar(' ') + i;
	if (nbpoint == 0 && **stritoa == 48)
		i = ft_putchar(' ') + i;
	return (i + len);
}
