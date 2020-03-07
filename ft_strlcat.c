/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:34:35 by ael-kass          #+#    #+#             */
/*   Updated: 2019/11/06 16:00:48 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strlcat(char *src, size_t size)
{
	size_t		i;
	size_t		f;
	size_t		a;
	char		*dst;

	if ((dst = (char *)malloc(size + 1)) == NULL)
		return (NULL);
	a = 0;
	i = 0;
	if (size == 0)
		return (dst);
	f = size;
	while (f-- > 0 && src[a] != '\0')
		dst[i++] = src[a++];
	dst[i] = '\0';
	return (dst);
}

int		help001(char **buffer, char **stritoa, int nbatoi)
{
	int		len;
	char	*stritoa1;

	stritoa1 = ft_strjoin(*buffer, *stritoa);
	ft_free(stritoa);
	ft_free(buffer);
	if (nbatoi > 0)
		ft_positive(&stritoa1, nbatoi, 1);
	if (nbatoi < 0)
		ft_negative(&stritoa1, nbatoi, 1);
	len = ft_putstr(stritoa1);
	ft_free(&stritoa1);
	return (len);
}
