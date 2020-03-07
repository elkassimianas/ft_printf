/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foncprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:38:33 by ael-kass          #+#    #+#             */
/*   Updated: 2020/01/08 11:07:31 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	b;
	char			*dst;

	b = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[b] != '\0')
		dst[i++] = s2[b++];
	dst[i] = '\0';
	return (dst);
}

int		ft_formatdep(const char **format, int nbatoi, va_list args)
{
	char					*stritoa;
	char					*buffer;
	unsigned long long		nbargs;

	if ((buffer = (char*)malloc(3)) == NULL)
		return (-1);
	buffer[0] = '0';
	buffer[1] = 'x';
	buffer[2] = '\0';
	nbargs = va_arg(args, unsigned long long);
	if (nbargs == 0 && *(*format - 1) == '.')
	{
		if ((stritoa = (char *)malloc(1)) == NULL)
			return (-1);
		*stritoa = '\0';
	}
	else
		stritoa = casdex1(nbargs);
	return (help001(&buffer, &stritoa, nbatoi));
}

char	*casdex1(unsigned long long nb1)
{
	char		*strhex;
	char		*buffer;
	int			a;

	strhex = "0123456789abcdef";
	a = nb_digit1(nb1);
	if ((buffer = (char *)malloc(a + 1)) == NULL)
		return (NULL);
	buffer[a] = '\0';
	a = a - 1;
	if (nb1 == 0)
		buffer[a] = strhex[nb1];
	while (nb1 != '\0' && a >= 0)
	{
		if (nb1 < 16)
		{
			buffer[a] = strhex[nb1];
			break ;
		}
		buffer[a--] = strhex[nb1 % 16];
		nb1 = nb1 / 16;
	}
	return (buffer);
}

int		nb_digit1(unsigned long long nb)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0 && nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int		ft_free(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
	return (-1);
}
