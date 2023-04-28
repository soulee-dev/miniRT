NAME=minirt-practice
CC=cc
# CFLAGS=-Wall -Wextra -Werror

SRCS:=
SRCS+=main.c
SRCS+=render.c
SRCS+=vec3_utils1.c
SRCS+=vec3_utils2.c
SRCS+=vec3_utils3.c
SRCS+=math_utils1.c
SRCS+=sphere.c
SRCS+=hit_record.c
SRCS+=hittable_list.c
SRCS+=inits.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ -I./mlx -O3 -g3

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -L./mlx -lmlx -framework OpenGL -framework AppKit -O3 -g3

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:
	make fclean
	make all

.PHONY: all clean fclean re