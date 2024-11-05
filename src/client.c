/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marksylaiev <marksylaiev@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:02:28 by marksylaiev       #+#    #+#             */
/*   Updated: 2024/11/05 21:18:44 by marksylaiev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	send_char(pid_t pid, char c)
{
	int	bit;

	for (int i = 7; i >= 0; --i)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <PID> <message>\n", argv[0]);
		return (1);
	}

	pid_t target_pid = atoi(argv[1]);
	char *message = argv[2];

	for (size_t i = 0; i <= strlen(message); ++i)
	{
		send_char(target_pid, message[i]);
	}

	return (0);
}