NAME=minirt-practice
CC=cc
CFLAGS=-Wall -Wextra -Werror

SRCS:=
SRCS+=main.c
SRCS+=render.c
SRCS+=hit_record.c
SRCS+=hittable_list.c
SRCS+=inits.c
SRCS+=camera.c

# Box
SRCS+=box/aabb.c
SRCS+=box/box_utils.c

# Shapes
SRCS+=shapes/sphere.c
SRCS+=shapes/moving_sphere.c
SRCS+=shapes/shape_utils.c

# Utils
SRCS+=utils/vec1.c
SRCS+=utils/vec2.c
SRCS+=utils/vec3.c
SRCS+=utils/vec4.c
SRCS+=utils/math1.c
SRCS+=utils/random1.c
SRCS+=utils/random2.c

# Materials
SRCS+=materials/lambertian.c
SRCS+=materials/metal.c
SRCS+=materials/dielectric.c

# REMOVE BEFORE FLIGHT
SRCS+=random_scene.c
SRCS+=progress/progress.c
# REMOVE BEFORE FLIGHT

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ -Imlx -O3 -g3

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