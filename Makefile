MLX_DIR = mlx
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11

SRC = cc   cub3D.c Raycasting/*.c parsing/*.c libft/*.c GarbageCollector/*.c get_next_line/*.c -lmlx -lXext -lX11 `sdl2-config --cflags --libs`

all:
	$(SRC) $(MLX_FLAGS) -lm 

clean:
	rm -f parsing/*.o libft/*.o Raycasting/*.o GarbageCollector/*.o libft/get_next_line/*.o

fclean: clean
	rm -f ./a.out

re: fclean all


#-g3 -fsanitize=address