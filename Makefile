
all:
	cc -Wall -Wextra -Werror -g3 cub3D.c parsing/*.c libft/*.c GarbageCollector/*.c get_next_line/*.c -lmlx -lXext -lX11 `sdl2-config --cflags --libs`

fclean:
	rm a.out