/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:24:20 by ael-kass          #+#    #+#             */
/*   Updated: 2020/01/09 12:39:06 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nb_digit(unsigned int nb)
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

char	*casdex(int nb, const char **format)
{
	char				*strhex;
	char				*strhex1;
	char				*buffer;
	unsigned int		nb1;
	int					a;

	strhex = "0123456789abcdef";
	strhex1 = "0123456789ABCDEF";
	nb1 = (unsigned int)nb;
	a = nb_digit(nb1);
	if ((buffer = (char *)malloc(a + 1)) == NULL)
		return (NULL);
	buffer[a--] = '\0';
	if (nb1 == 0)
		buffer[a] = strhex[nb1];
	while (nb1 != '\0' && a >= 0)
	{
		if (nb1 < 16)
			buffer[a] = (**format == 'X') ? strhex1[nb1] : strhex[nb1];
		buffer[a] = (**format == 'X') ? strhex1[nb1 % 16] : strhex[nb1 % 16];
		nb1 = nb1 / 16;
		a--;
	}
	return (buffer);
}
