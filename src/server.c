/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marksylaiev <marksylaiev@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:02:45 by marksylaiev       #+#    #+#             */
/*   Updated: 2024/11/05 22:00:05 by marksylaiev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handle_sigusr(int sig, t_message_state *state)
{
	state->current_char <<= 1;
	if (sig == SIGUSR2)
	{
		state->current_char |= 1;
	}
	state->bit_count++;
	if (state->bit_count == 8)
	{
		if (state->current_char == '\0')
		{
			printf("Received message: %s\n", state->message);
			free(state->message);
			exit(0);
		}
		state->message[state->char_index++] = state->current_char;
		state->bit_count = 0;
		state->current_char = 0;
	}
}

void	handle_signal_wrapper(int sig)
{
	static t_message_state	state = {0};

	if (state.message == NULL)
	{
		state.message = malloc(1024);
		state.bit_count = 0;
		state.current_char = 0;
		state.char_index = 0;
	}
	handle_sigusr(sig, &state);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_signal_wrapper;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Receiver PID: %d\n", getpid());
	printf("Waiting for message...\n");
	while (1)
	{
		pause();
	}
	return (0);
}
