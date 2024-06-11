/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:51:33 by lchapard          #+#    #+#             */
/*   Updated: 2023/11/28 11:09:05 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *type, ...);
int	ft_print_char(unsigned char c, int *error);
int	ft_convert_to(va_list arg, char c, int *error);
int	ft_print_string(char *str, int *error);
int	ft_strlenf(char *arg);
int	ft_print_int(int nbr, int cache, int *error);
int	ft_print_base(unsigned int nbr, char base, int cache, int *error);
int	ft_write_nb(unsigned int nbr, char *base, int cache, int *error);
int	ft_print_pointer(void *arg, int *error);
int	ft_print_adress(unsigned long addr, char *base, int cache, int *error);

#endif
