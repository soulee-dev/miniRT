NAME=minirt-practice
CC=cc
# CFLAGS=-Wall -Wextra -Werror

SRCS:=
SRCS+=main.c
SRCS+=vec_utils.c
SRCS+=progress/progress.c
SRCS+=render.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $(CPPFLAGS) $< -o $@ -Imlx

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:
	make fclean
	make all

.PHONY: all clean fclean re