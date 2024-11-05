# Vars
CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client
SRCDIR = src
OBJDIR = obj
SRC = server.c client.c
OBJS = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
SRCS = $(addprefix $(SRCDIR)/,$(SRC))

# Rules of files
all: $(OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJDIR)/server.o
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJDIR)/client.o

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rules of actions
.PHONY: all clean fclean re

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all