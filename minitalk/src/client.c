/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:26:56 by lchapard          #+#    #+#             */
/*   Updated: 2024/01/24 18:26:58 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile int	g_next;

int	ft_atoi(const char *str)
{
	int			sign;
	long int	total;
	size_t		i;

	i = 0;
	sign = 1;
	total = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		total = total * 10 + (str[i] - 48);
		if (total < 0 && sign > 0)
			return (-1);
		if (total < 0 && sign < 0)
			return (0);
		i++;
	}
	return (total * sign);
}

void	signal_handler_c(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	g_next = 1;
	if (signum == SIGUSR1)
	{
		ft_printf("\nSIGUSR1 received ... string printed ...\n");
		exit(0);
	}
}

void	char_to_bit(pid_t s_pid, char c)
{
	int	i;
	int	res;

	i = 7;
	res = 0;
	while (i >= 0)
	{
		g_next = 0;
		res = c >> i;
		res = res & 1;
		i--;
		if (res == 1)
		{
			kill(s_pid, SIGUSR2);
		}
		else
		{
			kill(s_pid, SIGUSR1);
		}
		while (g_next != 1)
			;
	}
}

void	send_sig(pid_t s_pid, char *str)
{
	size_t	i;

	write(1, "(Printing...)\n", 14);
	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		char_to_bit(s_pid, str[i]);
		i++;
	}
	char_to_bit(s_pid, str[i]);
}

int	main(int argc, char **argv)
{
	char				*str;
	pid_t				s_pid;
	struct sigaction	action;

	if (argc != 3)
		return (ft_printf("WRONG NUMBER OF ARGUMENTS!\n"));
	s_pid = ft_atoi(argv[1]);
	str = argv[2];
	if (s_pid < 0 || (kill(s_pid, 0) < 0))
		return (ft_printf("INVALID PID!\n"));
	action.sa_sigaction = signal_handler_c;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		return (ft_printf("SIGACTION ERROR!\n"));
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		return (ft_printf("SIGACTION ERROR!\n"));
	send_sig(s_pid, str);
	while (1)
		;
	return (argc);
}
