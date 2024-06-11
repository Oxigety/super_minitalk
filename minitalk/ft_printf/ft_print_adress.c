/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:47:33 by lchapard          #+#    #+#             */
/*   Updated: 2023/11/28 14:00:22 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_adress(unsigned long nbr, char *base, int cache, int *error)
{
	int	was_written;

	was_written = cache;
	if (nbr >= 16 && *error == 0)
	{
		was_written += ft_print_adress(nbr / 16, base, was_written, error);
		was_written += ft_print_char(base[nbr % 16], error);
	}
	if (nbr < 16 && *error == 0)
	{
		was_written += ft_print_string("0x", error);
		was_written += ft_print_char(base[nbr], error);
	}
	return (was_written);
}
