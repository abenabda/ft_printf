/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabda <abenabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:43:26 by abenabda          #+#    #+#             */
/*   Updated: 2026/11/05 11:52:28 by abenabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_memcpy(void *src)
{
	size_t	i;

	i = 0;
	while (((unsigned char *)src)[i])
	{
		ft_putchar(((unsigned char *)src)[i]);
		i++;
	}
}
