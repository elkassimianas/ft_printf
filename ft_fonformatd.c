/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonformatd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:51:32 by ael-kass          #+#    #+#             */
/*   Updated: 2020/01/11 15:34:19 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_positivecas0(char **stritoa, int nbatoi)
{
	char	*buffer;
	int		i;

	i = 0;
	if (nbatoi < 0)
		return (0);
	nbatoi = nbatoi - ft_strlen(*stritoa);
	if ((buffer = (char *)malloc(nbatoi + 1)) == NULL)
		return (-1);
	while (i < nbatoi)
		buffer[i++] = '0';
	if (nbatoi > 0)
	{
		buffer[i] = '\0';
		*stritoa = ft_strjoin(buffer, *stritoa);
		ft_free(&buffer);
	}
	return (0);
}

int		ft_negativecas0(char **stritoa, int nbatoi)
{
	char	*buffer;
	char	**stritoa1;
	int		i;

	i = 0;
	nbatoi = nbatoi - ft_strlen(*stritoa);
	if (nbatoi > 0)
	{
		if ((buffer = (char *)malloc(nbatoi + 2)) == NULL)
			return (-1);
		buffer[i] = '-';
		i = i + 1;
		while (i < nbatoi + 1)
			buffer[i++] = '0';
		buffer[i] = '\0';
		(*stritoa)++;
		stritoa1 = stritoa;
		*stritoa = ft_strjoin(buffer, *stritoa1);
		ft_free(&buffer);
	}
	return (0);
}

int		ft_positive(char **stritoa, int nbatoi, int nbpoint)
{
	char		*buffer;
	int			i;

	i = 0;
	nbatoi = nbatoi - ft_strlen(*stritoa);
	if (nbatoi < 0)
		return (0);
	if ((buffer = (char *)malloc(nbatoi + 1)) == NULL)
		return (-1);
	while (i < nbatoi)
		buffer[i++] = ' ';
	buffer[i] = '\0';
	if (nbpoint == 0 && **stritoa == 48)
		**stritoa = ' ';
	*stritoa = ft_strjoin(buffer, *stritoa);
	ft_free(&buffer);
	return (0);
}

int		ft_negative(char **stritoa, int nbatoi, int nbpoint)
{
	char	*buffer;
	int		i;

	i = 0;
	nbatoi = -1 * nbatoi;
	nbatoi = nbatoi - ft_strlen(*stritoa);
	if (nbatoi < 0)
		return (0);
	if ((buffer = (char *)malloc(nbatoi + 1)) == NULL)
		return (-1);
	while (i < nbatoi)
		buffer[i++] = ' ';
	buffer[i] = '\0';
	if (nbpoint == 0 && **stritoa == 48)
		**stritoa = ' ';
	*stritoa = ft_strjoin(*stritoa, buffer);
	ft_free(&buffer);
	return (0);
}
