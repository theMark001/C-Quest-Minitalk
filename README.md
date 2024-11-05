1. 
	- ./my_server

2. 
	- ps aux | grep "[m]y_server"
	- ./my_client PID


--- 

# client 
kill(PID, SIGUSR1);

•	int kill(pid_t pid, int sig);
	•	pid: Specifies the process ID to which the signal will be sent.
	•	sig: Specifies the signal to be sent (e.g., SIGUSR1, SIGTERM, etc.).

SIGUSR1 and SIGUSR2 are designed to be user-defined signals, which means you can assign them any meaning or behavior within your program.


# server
signal(SIGUSR1, signal_handler);

1. void ( *signal ( ""int signum"", ""void (*handler)(int)"" )  )(int);
	- int signum - It's signal
	- void (*handler)(int) - The second argument, signal_handler, is a function pointer to the function that should be called when SIGUSR1 is received by this process.


while (1) {
	pause();
}

2. This is an infinite loop, meaning the program will continue running until it is manually terminated or receives a signal that makes it exit.
	- pause() - is a system call that makes the process sleep until a signal is received.


