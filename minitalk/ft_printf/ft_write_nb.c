/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:20:21 by lchapard          #+#    #+#             */
/*   Updated: 2023/11/28 15:15:38 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_write_nb(unsigned int nbr, char *base, int cache, int *error)
{
	int				was_written;
	unsigned int	length_base;

	was_written = cache;
	length_base = ft_strlenf(base);
	if (nbr >= length_base && *error == 0)
	{
		was_written += ft_write_nb(nbr / length_base, base, was_written,
				error);
		was_written += ft_print_char(base[nbr % length_base], error);
	}
	if (nbr < length_base && *error == 0)
	{
		was_written += ft_print_char(base[nbr], error);
		return (was_written);
	}
	return (was_written);
}
