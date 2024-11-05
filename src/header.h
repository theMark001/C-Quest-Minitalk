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

#ifndef HEADER_H
# define HEADER_H

# include <signal.h> // For signal handling functions and SIGUSR1/SIGUSR2
# include <stdio.h>  // For printf
# include <stdlib.h> // For malloc, free, exit
# include <unistd.h> // For getpid and pause

size_t	ft_strlen(const char *s);
int		ft_printf(const char *format, ...);

#endif