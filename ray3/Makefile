NAME=minirt-practice
CC=cc
CFLAGS=-Wall -Wextra -Werror

SRCS:=
SRCS+=main.c
SRCS+=render.c

SRCS+=camera.c
SRCS+=canvas.c
SRCS+=ray.c

# Utils
SRCS+=utils/math1.c
SRCS+=utils/random1.c
SRCS+=utils/random2.c
SRCS+=utils/vec1.c
SRCS+=utils/vec2.c
SRCS+=utils/vec3.c
SRCS+=utils/vec4.c

# Get Next Line
SRCS+=get_next_line/get_next_line.c
SRCS+=get_next_line/get_next_line_utils.c

LIBFT=./libft/libft.a

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ -Imlx -O3 -g3

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -o $(NAME) -Llibft -lft -lmlx -framework OpenGL -framework AppKit -O3 -g3

$(LIBFT):
	make -C ./libft bonus

clean:
	make clean -C ./libft
	rm -f ${OBJS}

fclean: clean
	make fclean -C ./libft
	rm -f ${NAME}

re:
	make fclean
	make all

.PHONY: all clean fclean re