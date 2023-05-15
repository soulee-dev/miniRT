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
SRCS+=shapes/xy_rect.c
SRCS+=shapes/cylinder.c
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
SRCS+=materials/diffuse_light.c
SRCS+=materials/material_utils.c

# Textures
SRCS+=textures/solid_color.c
SRCS+=textures/checker.c
SRCS+=textures/texture_utils.c

# Get Next Line
SRCS+=get_next_line/get_next_line.c
SRCS+=get_next_line/get_next_line_utils.c

# REMOVE BEFORE FLIGHT
SRCS+=random_scene.c
SRCS+=progress/progress.c
# REMOVE BEFORE FLIGHT

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