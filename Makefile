SRC = cc src/cub3D.c src/music.c src/put_img.c src/Raycasting/*.c src/parsing/*.c help/libft/*.c help/GarbageCollector/*.c help/get_next_line/*.c -lmlx -lXext -lX11 -lm `sdl2-config --cflags --libs`

all:
	$(SRC)

fclean: clean
	rm ./a.out

re: fclean all


#-g3 -fsanitize=address