NAME	= libllist.so

CC	= gcc

RM	= rm -f

SRCS	= ./llist.c \
			./llist_node.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -Wall -Wextra
CFLAGS += -fPIC

LDFLAGS += -shared

all: $(NAME)
	cp $(NAME) ..

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
