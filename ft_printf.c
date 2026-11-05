/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabda <abenabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:43:15 by abenabda          #+#    #+#             */
/*   Updated: 2026/11/05 12:25:48 by abenabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printf_conditions(va_list ap, const char *format, int *i)
{
	(*i)++;
	if (format[(*i)] == 'd')
		ft_putnbr(va_arg(ap, int));
	if (format[(*i)] == 'c')
		ft_putchar(va_arg(ap, int));
	if (format[(*i)] == 's')
		ft_putstr(va_arg(ap, char *));
	if (format[(*i)] == '%')
		ft_putchar('%');
	if (format[(*i)] == 'x')
		ft_putnbr_hex(va_arg(ap, int), 0);
	if (format[(*i)] == 'X')
		ft_putnbr_hex(va_arg(ap, int), 1);
	if (format[(*i)] == 'u')
		ft_putnbr_unsigned(va_arg(ap, unsigned int));
	if (format[(*i)] == 'i')
		ft_putnbr(va_arg(ap, int));
	if (format[(*i)] == 'p')
		ft_putnbr_unsigned(va_arg(ap, unsigned int));
	if (format[(*i) + 1] != '\0')
		(*i)++;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	if (!format)
		return (0);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			printf_conditions(ap, format, &i);
		ft_putchar(format[i]);
		i++;
	}
	return (i);
}
