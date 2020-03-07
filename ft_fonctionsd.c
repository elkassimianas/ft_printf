/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finctionsd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:23:13 by ael-kass          #+#    #+#             */
/*   Updated: 2020/01/11 15:47:16 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putnbr(int n)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = n * (-1);
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
}

int		ft_putstr(char *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
