NAME=minirt-practice
CC=cc

LIBS_DIR=./libs
LIBFT_DIR=$(LIBS_DIR)/libft
SRC_DIR=./srcs/
INCLUDES_DIR = ./includes/

CFLAGS=-Wall -Wextra -Werror -I$(INCLUDES_DIR) -Imlx -O3 -g3
LIB=-L$(LIBFT_DIR) -lft -lmlx -framework OpenGL -framework AppKit -O3 -g3

SRCS:=
SRCS+=main.c
SRCS+=render.c

# scene
SRCS+=scene/canvas.c
SRCS+=scene/object_create.c
SRCS+=scene/scene.c

# trace
SRCS+=trace/ray.c
SRCS+=trace/hit/hit_sphere.c
SRCS+=trace/hit/hit.c
SRCS+=trace/hit/normal.c

# utils
SRCS+=utils/math1.c
SRCS+=utils/random1.c
SRCS+=utils/random2.c
SRCS+=utils/vec1.c
SRCS+=utils/vec2.c
SRCS+=utils/vec3.c
SRCS+=utils/vec4.c
SRCS+=utils/object1.c

LIBFT=$(LIBFT_DIR)/libft.a

SRC=$(addprefix $(SRC_DIR), $(SRCS))

# get_next_line
SRC+=$(LIBS_DIR)/get_next_line/get_next_line.c
SRC+=$(LIBS_DIR)/get_next_line/get_next_line_utils.c

OBJS = $(SRC:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -o $(NAME) $(LIB)

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

clean:
	make clean -C $(LIBFT_DIR)
	rm -f ${OBJS}

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f ${NAME}

re:
	make fclean
	make all

.PHONY: all clean fclean re