#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>      // For printf
#include <stdlib.h>     // For malloc, free, exit
#include <signal.h>     // For signal handling functions and SIGUSR1/SIGUSR2
#include <unistd.h>     // For getpid and pause

size_t  ft_strlen(const char *s);
int		ft_printf(const char *format, ...);

#endif