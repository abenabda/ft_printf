/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabda <abenabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:43:33 by abenabda          #+#    #+#             */
/*   Updated: 2026/11/05 12:26:25 by abenabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr_hex(unsigned int n, int isUpper);
void	ft_putnbr_unsigned(unsigned int n);

#endif