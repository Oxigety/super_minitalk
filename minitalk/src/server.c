/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:18:30 by lchapard          #+#    #+#             */
/*   Updated: 2024/01/24 14:18:32 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

unsigned char	*g_output;

void	print_message(void)
{
	write(1, g_output, ft_strlen(g_output, 0));
	write(1, "\n", 1);
}

void	extend_string(unsigned char **str, int *cpt)
{
	*str = ft_calloc(50, 1, false);
	if (*str == NULL)
	{
		free(g_output);
		exit(0);
	}
	g_output = ft_strjoin(g_output, *str, cpt);
	if (g_output == NULL)
	{
		free(*str);
		exit(0);
	}
	free(*str);
}

void	add_to_string(char c, bool print, bool fail)
{
	unsigned char		*str;
	static int			start = -1;
	static int			n = 1;
	static int			i = 0;
	static int			cpt = 0;

	if (start == -1)
	{
		g_output = ft_calloc(50, 1, true);
		reset_string_var(&start, &n, &i, &cpt);
	}
	if (c)
	{
		if (i == cpt)
			extend_string(&str, &cpt);
		g_output[i++] = c;
	}
	else if (c == 0 || fail)
	{
		start = -1;
		g_output[i] = '\0';
		if (print == true)
			print_message();
	}
}

void	reset_parameters(int *ascii, int *byte, bool freed)
{
	*ascii = 0;
	*byte = 0;
	if (freed)
	{
		free(g_output);
		g_output = NULL;
	}
}

void	signal_handler_s(int signum, siginfo_t *info, void *context)
{
	static int	current_byte = 0;
	static int	ascii = 0;
	static int	previous_pid = 0;
	static int	killed = 0;

	(void) context;
	if (check_same_client(info->si_pid, &previous_pid, &killed))
	{
		reset_parameters(&ascii, &current_byte, true);
		return ;
	}
	if (signum == SIGUSR2)
		ascii += (128 >> current_byte);
	if (++current_byte == 8)
	{
		add_to_string(ascii, true, false);
		if (ascii == 0)
		{
			end_client(&previous_pid, info->si_pid);
			reset_parameters(&ascii, &current_byte, true);
			return ;
		}
		reset_parameters(&ascii, &current_byte, false);
	}
	kill(info->si_pid, SIGUSR2);
}
