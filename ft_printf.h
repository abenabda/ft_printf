/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabda <abenabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:00:00 by abenabda          #+#    #+#             */
/*   Updated: 2026/11/05 13:00:00 by abenabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_len(char c);
int	ft_putstr_len(char *s);
int	ft_putnbr_len(int n);
int	ft_putunsigned_len(unsigned int n);
int	ft_puthex_len(unsigned int n, int is_upper);
int	ft_putptr_len(void *ptr);

#endif
