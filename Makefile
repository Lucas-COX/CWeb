NAME	= my_server

CC	= gcc

RM	= rm -f

SRCS	= ./src/connection.c \
		  ./src/main.c \
		  ./src/server.c \
		  ./src/signal.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
