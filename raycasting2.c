/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 03:21:46 by tasian            #+#    #+#             */
/*   Updated: 2021/02/28 03:21:47 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

float	choose_flag(t_data *data, float *hitx, float *hity)
{
	int wall_texture_x;
	int	wall_texture_y;

	wall_texture_x = 0;
	wall_texture_y = 0;
	if (fabs(*hitx) < fabs(*hity))
	{
		if (fabs(fabs(*hitx) - fabs(*hity)) > STEP)
			data->flag = *hitx >= 0 ? 1 : 2;
	}
	else if (fabs(fabs(*hitx) - fabs(*hity)) > STEP)
		data->flag = *hity >= 0 ? 3 : 4;
	wall_texture_x = data->flag == 1 ? data->ea.sizex : wall_texture_x;
	wall_texture_y = data->flag == 1 ? data->ea.sizey : wall_texture_y;
	wall_texture_x = data->flag == 2 ? data->we.sizex : wall_texture_x;
	wall_texture_y = data->flag == 2 ? data->we.sizey : wall_texture_y;
	wall_texture_x = data->flag == 3 ? data->so.sizex : wall_texture_x;
	wall_texture_y = data->flag == 3 ? data->so.sizey : wall_texture_y;
	wall_texture_x = data->flag == 4 ? data->no.sizex : wall_texture_x;
	wall_texture_y = data->flag == 4 ? data->no.sizey : wall_texture_y;
	*hitx = fabs(*hitx) > fabs(*hity) ? *hitx * wall_texture_x : \
	*hity * wall_texture_x;
	*hitx = *hitx < 0 ? *hitx + wall_texture_x : *hitx;
	return (wall_texture_y);
}

void	draw_line_part_two(t_data *data, float h1, float h2, int x)
{
	int				count;
	float			hitx;
	float			hity;
	unsigned int	color;

	count = 0;
	hitx = data->player.rayx - floor(data->player.rayx + 0.5);
	hity = data->player.rayy - floor(data->player.rayy + 0.5);
	data->flag_text = choose_flag(data, &hitx, &hity);
	while (count < data->size_map_y)
	{
		if (count < h1)
			mlx_put_pixel(&data->bas, x, count, data->sauce.ceiling);
		else if (count >= h1 && count <= h2)
		{
			color = mlx_get_pixel_color(data, hitx, \
				(data->flag_text / (h2 - h1)) * (count - h1), data->flag);
			if (color == 0xFF000000)
				color = 0;
			mlx_put_pixel(&data->bas, x, count, color);
		}
		else
			mlx_put_pixel(&data->bas, x, count, data->sauce.floor);
		count++;
	}
}

void	draw_line(t_data *data, double c, int x)
{
	float	h1;
	float	h2;

	if (c)
		h2 = (data->size_map_y / 2) * (1 + 1 / c);
	if (c)
		h1 = (data->size_map_y / 2) * (1 - 1 / c);
	else
	{
		h1 = data->size_map_y / 2;
		h2 = data->size_map_y / 2;
	}
	draw_line_part_two(data, h1, h2, x);
}

void	raycasting_part_three(t_data *s, float c, float a, int x)
{
	int			see;
	float		cousin;
	float		sinod;

	cousin = cos(a);
	sinod = sin(a);
	s->flag_sprite = 0;
	while (c < LOV)
	{
		see = 0;
		if (mlx_get_pixel_color(s, s->player.rayx, \
					s->player.rayy, 0) == WCL)
		{
			draw_line(s, (c * cos(a - s->player.angle)), x);
			s->x_buffer[x] = c;
			see = 1;
			break ;
		}
		c += STEP;
		s->player.rayx = s->player.posx + (cousin * c);
		s->player.rayy = s->player.posy + (sinod * c);
	}
	if (!see)
		draw_line(s, 0, x);
}
