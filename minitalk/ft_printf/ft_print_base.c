/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:15:54 by lchapard          #+#    #+#             */
/*   Updated: 2023/11/28 14:30:39 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_base(unsigned int nbr, char base, int cache, int *error)
{
	int		printed;
	char	*base_hex_low;
	char	*base_hex_up;
	char	*base_dec_uns;

	printed = cache;
	base_hex_low = "0123456789abcdef";
	base_hex_up = "0123456789ABCDEF";
	base_dec_uns = "0123456789";
	if (base == 'x')
		printed += ft_write_nb(nbr, base_hex_low, printed, error);
	else if (base == 'X')
		printed += ft_write_nb(nbr, base_hex_up, printed, error);
	else
		printed += ft_write_nb(nbr, base_dec_uns, printed, error);
	return (printed);
}
