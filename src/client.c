/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marksylaiev <marksylaiev@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:02:28 by marksylaiev       #+#    #+#             */
/*   Updated: 2024/11/05 21:48:25 by marksylaiev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	send_char(pid_t pid, char c)
{
	int	bit;
	int	current_bit;

	bit = 7;
	while (bit >= 0)
	{
		current_bit = (c >> bit) & 1;
		if (current_bit == 0)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(100);
		bit--;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	target_pid;
	char	*message;
	size_t	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <message>\n", argv[0]);
		return (1);
	}
	target_pid = atoi(argv[1]);
	message = argv[2];
	while (i <= ft_strlen(message))
	{
		send_char(target_pid, message[i]);
		i++;
	}
	return (0);
}
