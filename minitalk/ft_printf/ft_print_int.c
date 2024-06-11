/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:46:53 by lchapard          #+#    #+#             */
/*   Updated: 2023/11/28 14:09:09 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_int(int nbr, int cache, int *error)
{
	int	was_written;

	was_written = cache;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		was_written += ft_print_char('-', error);
		nbr = nbr * -1;
	}
	if (nbr >= 10 && *error == 0)
	{
		was_written = ft_print_int(nbr / 10, was_written, error);
		was_written += ft_print_char(nbr % 10 + '0', error);
	}
	if (nbr < 10 && *error == 0)
		was_written += ft_print_char(nbr % 10 + '0', error);
	return (was_written);
}
