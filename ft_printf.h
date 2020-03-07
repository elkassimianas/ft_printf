/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 08:53:17 by htagrour          #+#    #+#             */
/*   Updated: 2020/01/11 15:47:57 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>

int		ft_printf(const char *format, ...);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(const char **format, int n);
int		ft_formatd(const char **format, int nbatoi, va_list args);
int		ft_formatd2(const char **format, int nbatoi, int nbpoint, va_list args);
int		ft_formatd1(const char **format, int nbatoi, va_list args);
int		ft_positive(char **stritoa, int nbatoi, int nbpoint);
int		ft_negative(char **stritoa, int nbatoi, int nbpoint);
int		ft_positivecas0(char **stritoa, int nbatoi);
int		ft_negativecas0(char **stritoa, int nbatoi);
int		ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_putnbr(int n);
size_t	ft_strlen(const char *str);
int		ft_extradata(const char **format, va_list args);
int		ft_atoi(const char **str, va_list args);
char	*helpconversionu(unsigned int n);
char	*casdex(int nb, const char **format);
int		ft_formatdep(const char **format, int nbatoi, va_list args);
int		formatdes(int nbpoint, int nbatoi, va_list args);
int		ft_positivespace(char **stritoa, int nbatoi, int nbpoint);
int		ft_negativespace(char **stritoa, int nbatoi, int nbpoint);
char	*casdex1(unsigned long long nb1);
int		nb_digit1(unsigned long long nb);
char	*ft_strlcat(char *src, size_t size);
int		ft_free(char **s);
int		ft_formatdec(int nbwidth, va_list args);
int		help13(const char *format, va_list args, int len1, int len);
int		help01(const char **format, va_list args, int nbwidth);
int		help02(const char **format, va_list args, int nbwidth);
int		help001(char **buffer, char **stritoa, int nbatoi);
char	*help005(va_list args, int nbpoint, int nbatoi, char **stritoa);
char	*helpformatd2(int nbargs, const char **format);
int		helpformad02(int nbatoi, char *stritoa, int nbpoint, int nbargs);
int		ft_positivedec(char **stritoa, int nbatoi, int nbpoint);
int		ft_negativedec(char **stritoa, int nbatoi, int nbpoint);

#endif
