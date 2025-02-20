/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:08:58 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/20 20:42:32 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_putnbr(int n);
int		ft_putchar(int c);
int		ft_printunsigned(unsigned int n);
int		ft_printhexalower(unsigned int n);
int		ft_printhexaupper(unsigned int n);
int		ft_putstr(char *str);
int		ft_printaddress(void *ptr);

#endif