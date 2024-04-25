NAME	= librequests.so

CC	= gcc

RM	= rm -f

SRCS	= ./parse/attributes.c \
		  ./parse/headline.c \
		  ./parse/parse.c \
		  ./receive.c \
		  ./response.c \
		  ./request.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -I ../
CFLAGS += -Wall -Wextra -g3
CFLAGS += -fPIC

LDFLAGS += -shared
LDFLAGS += -L ../
LDFLAGS += -lmap

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
