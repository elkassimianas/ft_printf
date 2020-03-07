/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:58:58 by ael-kass          #+#    #+#             */
/*   Updated: 2020/01/08 10:47:22 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		help1(va_list args)
{
	int		nb;
	int		sign;

	sign = 1;
	nb = va_arg(args, int);
	return (nb * sign);
}

int		ft_atoi(const char **str, va_list args)
{
	long		nb;
	int			sign;

	nb = 0;
	sign = 1;
	while (**str == '-' || **str == '0')
	{
		sign = -1;
		(*str)++;
	}
	if (**str == '*')
	{
		nb = help1(args);
		if (nb < 0)
			sign = 1;
		(*str)++;
	}
	while (**str >= 48 && **str <= 57)
	{
		if (nb < 0)
			return ((sign > 0) ? -1 : 0);
		nb = nb * 10 + (**str - 48);
		(*str)++;
	}
	return (nb * sign);
}
