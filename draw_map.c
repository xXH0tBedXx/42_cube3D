/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 00:18:35 by tasian            #+#    #+#             */
/*   Updated: 2021/02/28 00:18:37 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	validate_sprites(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->size_map_y)
	{
		while (x < data->size_map_x)
		{
			if (mlx_get_pixel_color(data, x, y, 0) == SCL)
				if ((mlx_get_pixel_color(data, x + 1, y, 0) == 0x00000000) ||\
				(mlx_get_pixel_color(data, x, y + 1, 0) == 0x00000000) ||\
				(mlx_get_pixel_color(data, x - 1, y, 0) == 0x00000000) ||\
				(mlx_get_pixel_color(data, x, y - 1, 0) == 0x00000000) ||\
				(mlx_get_pixel_color(data, x + 1, y + 1, 0) == 0x00000000) ||\
				(mlx_get_pixel_color(data, x - 1, y - 1, 0) == 0x00000000) ||\
				(mlx_get_pixel_color(data, x + 1, y - 1, 0) == 0x00000000) ||\
				(mlx_get_pixel_color(data, x - 1, y + 1, 0) == 0x00000000))
					error_parser(5);
			x++;
		}
		y++;
		x = 0;
	}
}

void	validate_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->size_map_y)
	{
		while (x < data->size_map_x)
		{
			if (mlx_get_pixel_color(data, x, y, 0) == data->sauce.floor)
				if ((mlx_get_pixel_color(data, x + 1, y, 0) == 0x00000000) ||\
				(mlx_get_pixel_color(data, x, y + 1, 0) == 0x00000000) ||\
				(mlx_get_pixel_color(data, x - 1, y, 0) == 0x00000000) ||\
				(mlx_get_pixel_color(data, x, y - 1, 0) == 0x00000000) ||\
				(mlx_get_pixel_color(data, x + 1, y + 1, 0) == 0x00000000) ||\
				(mlx_get_pixel_color(data, x - 1, y - 1, 0) == 0x00000000) ||\
				(mlx_get_pixel_color(data, x + 1, y - 1, 0) == 0x00000000) ||\
				(mlx_get_pixel_color(data, x - 1, y + 1, 0) == 0x00000000))
					error_parser(5);
			x++;
		}
		y++;
		x = 0;
	}
	validate_sprites(data);
}

void	init_textures(t_data *data)
{
	data->bas.ptr = mlx_new_image(data->mlx, data->size_map_x, \
	data->size_map_y);
	data->bas.addr = mlx_get_data_addr(data->bas.ptr, &data->bas.bpp, \
	&data->bas.length, &data->bas.endian);
	init_textures2(data);
	if (!(data->so.ptr = mlx_xpm_file_to_image(data->mlx, data->sauce.so, \
	&data->so.sizex, &data->so.sizey)))
		error_parser(2);
	data->so.addr = mlx_get_data_addr(data->so.ptr, &data->so.bpp, \
	&data->so.length, &data->so.endian);
	if (!(data->sprite.ptr = mlx_xpm_file_to_image(data->mlx, data->sauce.sp, \
	&data->sprite.sizex, &data->sprite.sizey)))
		error_parser(2);
	data->sprite.addr = mlx_get_data_addr(data->sprite.ptr, &data->sprite.bpp, \
	&data->sprite.length, &data->sprite.endian);
}

void	set_angle(t_data *data, char *flag)
{
	if (*(flag) == 'N')
		data->player.angle = M_PI + M_PI_2;
	else if (*(flag) == 'W')
		data->player.angle = M_PI;
	else if (*(flag) == 'E')
		data->player.angle = 0;
	else if (*(flag) == 'S')
		data->player.angle = M_PI_2;
}

void	draw_map(t_data *data, char *line, int number)
{
	unsigned int	counter;

	backslash_zero(line[0]);
	counter = 0;
	while (*(line + counter) != '\0')
	{
		draw_pixel(line, counter, number, data);
		if (*(line + counter) == 'N' || *(line + counter) == 'E' || \
		*(line + counter) == 'W' || *(line + counter) == 'S')
		{
			if (data->player.posy || data->player.posx)
				error_parser(5);
			data->player.posy = number + 0.5;
			data->player.posx = counter + 0.5;
			set_angle(data, line + counter);
			mlx_put_pixel(&data->map, counter, number, data->sauce.floor);
		}
		if (*(line + counter) != '0' && *(line + counter) != '1' &&\
		*(line + counter) != '2' && *(line + counter) != 'N' &&\
		*(line + counter) != 'W' && *(line + counter) != 'S' &&\
		*(line + counter) != 'E' && *(line + counter) != ' ' &&\
		*(line + counter) != '\0')
			error_parser(5);
		counter++;
	}
}
