/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabda <abenabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:00:00 by abenabda          #+#    #+#             */
/*   Updated: 2026/11/05 13:00:00 by abenabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_base(unsigned long n, int is_upper)
{
	int	count;
	int	ret;

	count = 0;
	if (n >= 16)
	{
		count = ft_puthex_base(n / 16, is_upper);
		if (count < 0)
			return (-1);
	}
	if (is_upper)
		ret = ft_putchar_len("0123456789ABCDEF"[n % 16]);
	else
		ret = ft_putchar_len("0123456789abcdef"[n % 16]);
	if (ret < 0)
		return (-1);
	return (count + ret);
}

int	ft_puthex_len(unsigned int n, int is_upper)
{
	return (ft_puthex_base(n, is_upper));
}

int	ft_putptr_len(void *ptr)
{
	int	count;
	int	ret;

	if (!ptr)
		return (ft_putstr_len("(nil)"));
	count = ft_putstr_len("0x");
	if (count < 0)
		return (-1);
	ret = ft_puthex_base((unsigned long)ptr, 0);
	if (ret < 0)
		return (-1);
	return (count + ret);
}
