.PHONY: all clean fclean re
NAME := cub3D
SRC := main.c tools.c tools2.c cubed_trim.c map_parser.c init_textures.c sort_sprites.c map_parser2.c draw_map.c move.c write_bmp.c bmp_utils.c raycasting.c raycasting2.c\
get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ := $(SRC:%.c=%.o)
INCLUDES := cubed.h bmp.h get_next_line_bonus.h
HDR := ./headers
LIBS := libft.a libmlx.a
vpath %.h $(HDR)

all: $(NAME) 

$(NAME): $(OBJ) $(LIBS)
	@$(MAKE) -C libft
	@$(MAKE) -C libmlx
	gcc -Wall -Wextra -Werror -I $(HDR) -L libft -lft -L libmlx -lmlx $(OBJ) -framework OpenGL -framework Appkit -o $(NAME)

libft.a:
	@$(MAKE) -C libft

libmlx.a:
	@$(MAKE) -C libmlx

%.o: %.c $(INCLUDES)
	gcc -c -Wall -Wextra -Werror $< -I $(HDR) -o $@

clean:
	$(MAKE) clean -C libmlx
	$(MAKE) clean -C libft
	rm -rf $(OBJ)

fclean: clean
	rm -f libmlx/libmlx.a
	rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all