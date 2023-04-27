NAME=minirt-practice
CC=cc
# CFLAGS=-Wall -Wextra -Werror

SRCS:=
SRCS+=main.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $(CPPFLAGS) $< -o $@ -Imlx -O3 -g3

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lmlx -framework OpenGL -framework AppKit -O3 -g3

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:
	make fclean
	make all

.PHONY: all clean fclean re