/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:23:59 by ael-kass          #+#    #+#             */
/*   Updated: 2020/01/09 11:26:10 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*condit(char *dst, unsigned int n, int i)
{
	int		a;

	if (n > 0)
	{
		while (n != 0)
		{
			a = n % 10;
			n = n / 10;
			dst[i] = a + 48;
			i--;
		}
		return (dst);
	}
	if (n == 0)
		dst[i] = n + 48;
	return (dst);
}

char	*effect(char *dst, int n, int len, unsigned int e)
{
	int				i;
	unsigned int	b;

	i = len - 1;
	dst[i + 1] = '\0';
	if (n < 0)
	{
		dst[0] = 45;
		b = n * (-1);
		dst = condit(dst, b, i);
		return (dst);
	}
	else if (e > 0)
	{
		dst = condit(dst, e, i);
		return (dst);
	}
	else if (n == 0)
	{
		dst = condit(dst, e, i);
		return (dst);
	}
	return (NULL);
}

char	*ft_itoa(const char **format, int n)
{
	int				a;
	int				i;
	unsigned int	conversionu;
	char			*dst;

	i = 0;
	a = 0;
	if (n == 0)
	{
		dst = (char *)malloc(sizeof(char) * n + 2);
		return (dst == NULL ? (NULL) : effect(dst, a, 1, 0));
	}
	if ((a = n) < 0)
	{
		while (a /= 10)
			i++;
		i = i + 2;
		if (**format == 'u')
			i = 0;
	}
	conversionu = (unsigned int)n;
	if (**format == 'u' || n > 0)
		return (helpconversionu(conversionu));
	dst = (char *)malloc(i + 1);
	return (dst == NULL ? (NULL) : effect(dst, n, i, 0));
}

char	*helpconversionu(unsigned int n)
{
	int				i;
	char			*dst;
	unsigned int	e;

	e = n;
	i = 0;
	while (e > 0 && e != 0)
	{
		e = e / 10;
		i++;
	}
	dst = (char *)malloc(i + 1);
	if (dst == NULL)
		return (NULL);
	dst = effect(dst, 0, i, n);
	return (dst);
}
