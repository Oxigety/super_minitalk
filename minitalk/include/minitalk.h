/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:20:59 by lchapard          #+#    #+#             */
/*   Updated: 2024/01/24 14:21:00 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <unistd.h>
# include <signal.h>
# include <netinet/in.h>
# include <errno.h> 
# include <string.h>
# include <stdbool.h>
# include "../ft_printf/ft_printf.h"

void			send_sig(int s_pid, char *str);
void			signal_handler_s(int signum, siginfo_t *info, void *context);
void			signal_handler_c(int signum, siginfo_t *info, void *context);
int				ft_atoi(const char *str);
void			char_to_bit(pid_t s_pid, char c);
void			send_sig(pid_t s_pid, char *str);
int				check_same_client(int client, int *previous, int *killed);
void			end_client(int	*previous, pid_t client);
void			reset_string_var(int *start, int *n, int *i, int *cpt);
void			print_message(void);
void			extend_string(unsigned char **str, int *cpt);
void			add_to_string(char c, bool print, bool fail);
void			reset_parameters(int *ascii, int *byte, bool freed);
unsigned char	*ft_calloc(size_t nmemb, size_t size, bool start);
size_t			ft_strlen(const unsigned char *s, size_t n);
unsigned char	*alloc_join(unsigned char const *s1, unsigned char const *s2);
unsigned char	*ft_strjoin(unsigned char const *s1, unsigned char const *s2,
					int *cpt);

#endif
