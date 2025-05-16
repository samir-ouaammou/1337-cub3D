SRC = cc  cub3D.c music.c put_img.c Raycasting/*.c parsing/*.c libft/*.c GarbageCollector/*.c get_next_line/*.c -lmlx -lXext -lX11 -lm `sdl2-config --cflags --libs`

all:
	$(SRC)

fclean: clean
	rm ./a.out

re: fclean all


#-g3 -fsanitize=address