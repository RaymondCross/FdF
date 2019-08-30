NAME = fdf

FLAGS = -Wall -Wextra -Werror

SOURCES = srcs/main.c\
			srcs/parse.c\
			srcs/fdf.c\
			srcs/draw.c\
			srcs/drawline.c\
			srcs/hooks.c\
			srcs/math_functions.c\
			srcs/matrix_functions.c\
			srcs/toggle_keys.c\
			srcs/transform_hooks.c\
			srcs/destroy.c\

OBJECTS = $(SOURCES:.c=.o)
LIB_LINK = -L ./libft -lft
MLX_LINK = -L ./mlx -lmlx
FRAMEWORKS = -framework OpenGL -framework Appkit

$(NAME):
	make -C mlx/
	make -C libft/
	gcc -g $(SOURCES) $(FLAGS) $(LIB_LINK) $(MLX_LINK) $(FRAMEWORKS) -o $(NAME)

all: $(NAME)

clean:
	make -C libft/ clean
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean
	make -C mlx/ clean

re: fclean all
