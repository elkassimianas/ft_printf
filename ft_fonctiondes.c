/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctiondes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:04:07 by ael-kass          #+#    #+#             */
/*   Updated: 2020/01/08 15:37:26 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		formatdes(int nbpoint, int nbatoi, va_list args)
{
	char		*nbargs;
	int			nba;
	char		*stritoa;

	nbargs = help005(args, nbpoint, nbatoi, &stritoa);
	if (nbatoi > 0 && stritoa != NULL)
		ft_positivespace(&stritoa, nbatoi, nbpoint);
	if (nbatoi < 0 && stritoa != NULL)
		ft_negativespace(&stritoa, nbatoi, nbpoint);
	if (stritoa != NULL && stritoa != nbargs)
	{
		nba = ft_putstr(stritoa);
		ft_free(&stritoa);
	}
	else
		nba = ft_putstr(nbargs);
	return (nba);
}

char	*help005(va_list args, int nbpoint, int nbatoi, char **stritoa)
{
	char	*nbargs;

	*stritoa = NULL;
	nbargs = va_arg(args, char *);
	if (nbargs == NULL)
		nbargs = "(null)";
	if (nbpoint == 0 || nbatoi != 0)
		*stritoa = nbargs;
	if (nbpoint > 0)
		*stritoa = ft_strlcat(nbargs, nbpoint);
	if (nbpoint == -1)
	{
		*stritoa = "";
		nbargs = "";
	}
	return (nbargs);
}

int		ft_positivespace(char **stritoa, int nbatoi, int nbpoint)
{
	char		*buffer;
	int			i;

	i = 0;
	nbatoi = nbatoi - ft_strlen(*stritoa);
	if (nbatoi < 0)
		return (1);
	if ((buffer = (char *)malloc(nbatoi + 1)) == NULL)
		return (-1);
	while (i < nbatoi)
		buffer[i++] = ' ';
	buffer[i] = '\0';
	if (nbpoint == 0 && **stritoa == 48)
		**stritoa = ' ';
	*stritoa = ft_strjoin(buffer, *stritoa);
	ft_free(&buffer);
	return (1);
}

int		ft_negativespace(char **stritoa, int nbatoi, int nbpoint)
{
	char	*buffer;
	int		i;

	i = 0;
	nbatoi = -1 * nbatoi;
	nbatoi = nbatoi - ft_strlen(*stritoa);
	if (nbatoi < 0)
		return (1);
	if ((buffer = (char *)malloc(nbatoi + 1)) == NULL)
		return (-1);
	while (i < nbatoi)
		buffer[i++] = ' ';
	buffer[i] = '\0';
	if (nbpoint == 0 && **stritoa == 48)
		**stritoa = ' ';
	*stritoa = ft_strjoin(*stritoa, buffer);
	ft_free(&buffer);
	return (1);
}
