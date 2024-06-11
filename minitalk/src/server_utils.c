/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:35:05 by lchapard          #+#    #+#             */
/*   Updated: 2024/02/20 18:35:06 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	check_same_client(int client, int *previous, int *killed)
{
	if (*previous == 0)
	{
		if (*killed == 1)
		{
			*killed = 0;
			return (1);
		}
		*previous = client;
		return (0);
	}
	if (*previous != client)
	{
		write(1, "Already in use!\n", 16);
		add_to_string('\0', false, true);
		kill(client, SIGUSR1);
		kill(*previous, SIGUSR1);
		*previous = 0;
		*killed = 1;
		return (1);
	}
	return (0);
}

void	end_client(int	*previous, pid_t client)
{
	write(1, "Message was successfully received!\n", 35);
	kill(client, SIGUSR1);
	*previous = 0;
}

void	reset_string_var(int *start, int *n, int *i, int *cpt)
{
	*n = 1;
	*i = 0;
	*start = 1;
	*cpt = 50;
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = signal_handler_s;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		return (ft_printf("SIGACTION ERROR!\n"));
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		return (ft_printf("SIGACTION ERROR!\n"));
	ft_printf("(SERVER PID : %d)\n", getpid());
	while (1)
		;
	return (0);
}
