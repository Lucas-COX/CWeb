NAME	= my_server

CC	= gcc

RM	= rm -f

SRCS	= ./src/client.c \
		  ./src/config.c \
		  ./src/connection.c \
		  ./src/main.c \
		  ./src/server.c \
		  ./src/signal.c

OBJS	= $(SRCS:.c=.o)

CFLAGS += -I ./include/
CFLAGS += -I ./lib/
CFLAGS += -Wall -Wextra
CFLAGS += -g3

LDFLAGS += -Wl,-rpath=./lib/
LDFLAGS += -L./lib/
LDFLAGS += -lllist
LDFLAGS += -lrequests
LDFLAGS += -lmap

all: libs $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean: cleanlibs
	$(RM) $(OBJS)

cleanlibs:
	@make -C lib clean

fclean: clean fcleanlibs
	$(RM) $(NAME)

fcleanlibs:
	@make -C lib fclean

libs:
	@make -C lib

re: fclean all

.PHONY: all clean cleanlibs fclean fcleanlibs libs re
