/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabda <abenabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:00:00 by abenabda          #+#    #+#             */
/*   Updated: 2026/11/05 13:00:00 by abenabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_len(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_len(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	return (write(1, s, len));
}

static int	ft_putnbr_base(unsigned long n, char *base, unsigned long len)
{
	int	count;
	int	ret;

	count = 0;
	if (n >= len)
	{
		count = ft_putnbr_base(n / len, base, len);
		if (count < 0)
			return (-1);
	}
	ret = ft_putchar_len(base[n % len]);
	if (ret < 0)
		return (-1);
	return (count + ret);
}

int	ft_putnbr_len(int n)
{
	long	nbr;
	int		ret;

	nbr = n;
	if (nbr < 0)
	{
		if (ft_putchar_len('-') < 0)
			return (-1);
		ret = ft_putnbr_base(-nbr, "0123456789", 10);
		if (ret < 0)
			return (-1);
		return (ret + 1);
	}
	return (ft_putnbr_base(nbr, "0123456789", 10));
}

int	ft_putunsigned_len(unsigned int n)
{
	return (ft_putnbr_base(n, "0123456789", 10));
}
