/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 03:36:01 by tasian            #+#    #+#             */
/*   Updated: 2021/03/05 12:11:09 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include <string.h>
# include "libft.h"
# include "get_next_line_bonus.h"

# define WCL			0x00FACFAC
# define SCL			0x00FFFFFF
# define LOV			100
# define FOV			1.15192
# define BRICKSIZE		1
# define STEP			0.0009765625
# define MAX_SIZE		10000

typedef	struct	s_spirt
{
	float			dist;
	int				h_offset;
	int				v_offset;
}				t_spirt;

typedef struct	s_sprite {
	float			y;
	float			x;
	float			hitx;
	float			hity;
	float			dist;
	size_t			scale_sprite;
}				t_sprite;

typedef struct	s_text {
	void			*ptr;
	char			*addr;
	int				bpp;
	int				length;
	int				endian;
	int				sizex;
	int				sizey;
}				t_text;

typedef struct	s_player {
	float			posx;
	float			posy;
	float			rayx;
	float			rayy;
	float			angle;
}				t_player;

typedef struct	s_img {
	void			*ptr;
	char			*addr;
	int				bpp;
	int				length;
	int				endian;
}				t_img;

typedef struct	s_source {
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sp;
	unsigned int	floor;
	unsigned int	ceiling;
}				t_sources;

typedef struct	s_data {
	void		*mlx;
	void		*window;
	int			checker_map;
	float		size_map_x;
	float		size_map_y;
	char		flag_save;
	int			flag;
	int			flag_text;
	int			flag_sprite;
	int			sprite_counter;
	int			*x_buffer;
	t_list		*list;
	t_sprite	*sprites;
	t_text		sprite;
	t_player	player;
	t_sources	sauce;
	t_img		map;
	t_img		bas;
	t_text		no;
	t_text		so;
	t_text		we;
	t_text		ea;
}				t_data;

unsigned int	mlx_get_pixel_color(t_data *data, int x, int y, int flag);
void			raycasting_part_three(t_data *s, float c, float a, int x);
void			parse_textures_2(char *line, char **file, t_data *data);
void			main_parser(t_data *data, char *line, int *counter);
void			mlx_put_pixel(t_img *img, int x, int y, int color);
void			parse_resolution_norme(t_data *data, int x, int y);
void			draw_map(t_data *data, char	*line, int number);
void			validate_file(t_data *data, char *map_name);
void			manager_sprites(t_data *s, int x, int y);
char			ft_strcmp(char *string1, char *string2);
char			*color_trim(char *s1, const char *set);
int				button_pressed(int key, t_data *data);
int				create_trgb(int r, int g, int b);
int				closed(t_data *data, int flag);
void			init_textures2(t_data *data);
void			init_textures(t_data *data);
int				main(int argc, char **argv);
void			sort_sprites(t_data *data);
void			validate_map(t_data *data);
int				atoi_rgb(char *str);
void			raycasting(t_data *data);
void			error_parser(int flag);
char			**skips(char *line);
void			save_image_as_bmp(t_data *data, const char *name);
void			draw_pixel(char *line, int counter, int number, t_data *data);
int				cmp_xpm(char *line);
void			backslash_zero(char sym);
#endif
