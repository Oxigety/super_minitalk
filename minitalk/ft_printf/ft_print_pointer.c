/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:34:21 by lchapard          #+#    #+#             */
/*   Updated: 2023/11/28 14:09:34 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_pointer(void *arg, int *error)
{
	size_t	was_written;
	char	*base_x;

	base_x = "0123456789abcdef";
	was_written = 0;
	if (arg == 0)
		was_written += ft_print_string("(nil)", error);
	else
		was_written += ft_print_adress((unsigned long)arg, base_x, 0, error);
	return (was_written);
}
