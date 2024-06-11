/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:25:48 by lchapard          #+#    #+#             */
/*   Updated: 2024/02/05 18:04:01 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_strlenf(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

int	ft_print_string(char *str, int *error)
{
	int	length;

	if (str == NULL)
	{
		length = ft_print_string("(null)", error);
		return (length);
	}
	length = ft_strlenf(str);
	if (write(1, str, length) == -1)
		*error = -1;
	return (length);
}
