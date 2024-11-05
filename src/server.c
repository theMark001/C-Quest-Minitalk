/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marksylaiev <marksylaiev@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:02:45 by marksylaiev       #+#    #+#             */
/*   Updated: 2024/11/05 21:35:47 by marksylaiev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*message;
int		bit_count = 0;
char	current_char = 0;
int		char_index = 0;

void	handle_sigusr(int sig)
{
	current_char <<= 1;
	if (sig == SIGUSR2)
	{
		current_char |= 1;
	}
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
		{
			ft_printf("Received message: %s\n", message);
			free(message);
			exit(0);
		}
		message[char_index++] = current_char;
		bit_count = 0;
		current_char = 0;
	}
}

int	main(void)
{
	message = malloc(1024);
	struct sigaction sa;
	sa.sa_handler = handle_sigusr;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Receiver PID: %d\n", getpid());
	ft_printf("Waiting for message...\n");
	while (1)
	{
		pause();
	}
	return (0);
}
