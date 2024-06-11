/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:13:15 by lchapard          #+#    #+#             */
/*   Updated: 2023/11/30 14:17:28 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *type, ...)
{
	va_list	arg;
	int		was_printed;
	size_t	i;
	int		*error;
	int		n_error;

	va_start(arg, type);
	i = 0;
	was_printed = 0;
	n_error = 0;
	error = &n_error;
	while (type[i])
	{
		if (type[i] == '%' && type[i++])
			was_printed += ft_convert_to(arg, type[i++], error);
		else
			was_printed += ft_print_char(type[i++], error);
		if (*error != 0)
			return (-1);
	}
	va_end(arg);
	return (was_printed);
}

int	ft_convert_to(va_list arg, char c, int *error)
{
	int	printed;

	printed = 0;
	if (c == 'c')
		printed += ft_print_char((unsigned char)va_arg(arg, int), error);
	else if (c == 's')
		printed += ft_print_string((char *)va_arg(arg, char *), error);
	else if (c == 'i' || c == 'd')
		printed += ft_print_int((int )va_arg(arg, int), 0, error);
	else if (c == 'x' || c == 'X' || c == 'u')
		printed += ft_print_base((unsigned int)va_arg(arg, unsigned int), c,
				0, error);
	else if (c == 'p')
		printed += ft_print_pointer((void *)va_arg(arg, void *), error);
	else if (c == '%')
		printed += ft_print_char('%', error);
	else
		*error = -1;
	return (printed);
}
