/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabda <abenabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:55:04 by abenabda          #+#    #+#             */
/*   Updated: 2026/11/05 12:25:53 by abenabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

void	ft_putnbr_hex(unsigned int n, int isUpper)
{
	long	nbr;

	nbr = n;
	if (nbr >= 16)
		ft_putnbr_hex((nbr / 16), isUpper);
	if (isUpper)
		ft_putchar((nbr % 16)["0123456789ABCDEF"]);
	else
		ft_putchar((nbr % 16)["0123456789abcdef"]);
}

void	ft_putnbr_unsigned(unsigned int n)
{
	long	nbr;

	nbr = n;
	if (nbr > 9)
		ft_putnbr_unsigned(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, &(*s), 1);
		s++;
	}
}
