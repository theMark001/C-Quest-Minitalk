/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marksylaiev <marksylaiev@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:02:45 by marksylaiev       #+#    #+#             */
/*   Updated: 2024/11/05 20:43:45 by marksylaiev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void signal_handler(int signal) {
	if (signal == SIGUSR1) {
		printf("Received SIGUSR1 signal!\n");
	}
}
	
int main() {
  signal(SIGUSR1, signal_handler);

  while (1) {
    pause();
  }
}