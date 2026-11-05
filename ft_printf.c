/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabda <abenabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:00:00 by abenabda          #+#    #+#             */
/*   Updated: 2026/11/05 13:00:00 by abenabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar_len(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr_len(va_arg(ap, char *)));
	if (c == 'p')
		return (ft_putptr_len(va_arg(ap, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_len(va_arg(ap, int)));
	if (c == 'u')
		return (ft_putunsigned_len(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_puthex_len(va_arg(ap, unsigned int), 0));
	if (c == 'X')
		return (ft_puthex_len(va_arg(ap, unsigned int), 1));
	if (c == '%')
		return (ft_putchar_len('%'));
	return (-1);
}

static int	ft_loop(const char *format, va_list ap)
{
	int	count;
	int	ret;
	int	i;

	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret = ft_format(format[i + 1], ap);
			i++;
		}
		else
			ret = ft_putchar_len(format[i]);
		if (ret < 0)
			return (-1);
		count += ret;
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = ft_loop(format, ap);
	va_end(ap);
	return (count);
}
