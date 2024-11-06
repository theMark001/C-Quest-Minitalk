# Vars
CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER = my_server
CLIENT = my_client
SRCDIR = src
OBJDIR = obj
LIBFTDIR = libft
SRC = server.c client.c
OBJS = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
SRCS = $(addprefix $(SRCDIR)/,$(SRC))

# Rules of files
all: $(OBJS)
	$(CC) $(CFLAGS) -L$(LIBFTDIR) -lftprintf -lft -o $(SERVER) $(OBJDIR)/server.o
	$(CC) $(CFLAGS) -L$(LIBFTDIR) -lftprintf -lft -o $(CLIENT) $(OBJDIR)/client.o

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -c $< -o $@

# Rules of actions
.PHONY: all clean fclean re

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all