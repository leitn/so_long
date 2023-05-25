/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 06:07:30 by letnitan          #+#    #+#             */
/*   Updated: 2023/05/25 14:43:57 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

size_t	pf_strlen(const char *str);
int		pf_putstr(char	*str);
int		pf_putchar(char c);
int		pf_nbrcounter(long long nb, int base_len);
int		pf_putnbr(long long n, char *base, int trigger);
int		pf_checkflag(va_list args, const char c);
int		ft_printf(const char *mandatory_argument, ...);
int		pf_pointer(unsigned long long ptr, char *base, int trigger);
int		pf_ptrlen(unsigned long long n, int base_len);
#endif
