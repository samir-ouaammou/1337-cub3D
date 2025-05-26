SRCS =		src/cub3D.c \
			src/movement.c \
			src/movement_utils.c \
			src/movement_utils2.c \
			src/music.c \
			src/put_img.c \
			src/draw_textures/draw_textures.c \
			src/parsing/check_colors.c \
			src/parsing/check_dor_errors.c \
			src/parsing/check_map_errors.c \
			src/parsing/check_texture.c \
			src/parsing/main_parsins.c \
			src/parsing/read_map_file.c \
			src/parsing/set_player_and_map_size.c \
			src/Raycasting/Raycasting.c \
			src/Raycasting/Raycasting_utils.c \
			src/Raycasting/Raycasting_utils1.c \
			src/Raycasting/Raycasting_utils2.c \
			src/Raycasting/Raycasting_utils3.c

SRCS_HELP =	help/libft/ft_atoi.c \
			help/libft/ft_isdigit.c \
			help/libft/ft_itoa.c \
			help/libft/ft_split.c \
			help/libft/ft_strchr.c \
			help/libft/ft_strcmp.c \
			help/libft/ft_strdup.c \
			help/libft/ft_strjoin.c \
			help/libft/ft_strlcat.c \
			help/libft/ft_strlcpy.c \
			help/libft/ft_strlen.c \
			help/libft/ft_strrchr.c \
			help/libft/ft_strtrim.c \
			help/libft/ft_substr.c \
			help/libft/ft_memset.c \
			help/get_next_line/get_next_line.c \
			help/get_next_line/get_next_line_utils.c \
			help/GarbageCollector/malloc.c \
			help/GarbageCollector/malloc_utils.c


OBJS = $(SRCS:.c=.o)

OBJS_HELP = $(SRCS_HELP:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror  #-g -g3 -fsanitize=address

MLX = -lmlx -lXext -lX11 -lm

MUSIC = `sdl2-config --cflags --libs`

NAME = cub3D

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(SRCS_HELP)
	$(CC) $(CFLAGS) $(OBJS) $(SRCS_HELP) $(MLX) $(MUSIC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_HELP)

fclean: clean
	$(RM) $(NAME)

re: fclean all
