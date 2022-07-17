/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 02:59:31 by tasian            #+#    #+#             */
/*   Updated: 2021/02/28 03:02:07 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

size_t	draw_pixel_for_norm(t_data *s, size_t i, size_t j, t_spirt *sp)
{
	unsigned int color;

	color = mlx_get_pixel_color(s,
	i * s->sprite.sizex / s->sprites->scale_sprite,
	j * s->sprite.sizey / s->sprites->scale_sprite, 5);
	if (color != 0xFF000000)
		mlx_put_pixel(&s->bas, sp->h_offset + i, sp->v_offset + j,
		color);
	j++;
	return (j);
}

void	dspt(t_data *s, t_spirt sp)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (i < s->sprites->scale_sprite)
	{
		if (sp.h_offset + i < 0 || sp.h_offset + i >= s->size_map_x)
			i++;
		else if (s->x_buffer[sp.h_offset + i] + 0.8 < sp.dist)
			i++;
		else
		{
			j = 0;
			while (j < s->sprites->scale_sprite)
			{
				if (sp.v_offset + j < 0 || sp.v_offset + j >= s->size_map_y)
					j++;
				else
					j = draw_pixel_for_norm(s, i, j, &sp);
			}
			i++;
		}
	}
}

void	drow_sprites(t_data *s, t_sprite sprites)
{
	float	dir;
	t_spirt	spirt;

	dir = atan2f(sprites.y - s->player.posy, sprites.x - s->player.posx);
	while (dir - s->player.angle < -M_PI)
		dir += 2 * M_PI;
	while (dir - s->player.angle > M_PI)
		dir -= 2 * M_PI;
	spirt.dist = sqrt(pow(sprites.x - s->player.posx, 2)
		+ pow(sprites.y - s->player.posy, 2));
	s->sprites->scale_sprite = s->size_map_y / spirt.dist;
	spirt.h_offset = (dir - s->player.angle) / FOV * (s->size_map_x)
		+ s->size_map_x / 2 - s->sprites->scale_sprite / 2;
	spirt.v_offset = s->size_map_y / 2 - s->sprites->scale_sprite / 2;
	dspt(s, spirt);
}

void	raycasting_part_two(t_data *s, float a, int x, float c)
{
	while (x < s->size_map_x)
	{
		c = 0;
		s->player.rayx = s->player.posx;
		s->player.rayy = s->player.posy;
		raycasting_part_three(s, c, a, x);
		x++;
		a += FOV / s->size_map_x;
	}
}

void	raycasting(t_data *data)
{
	float	a;
	int		x;
	int		i;
	float	c;

	i = 0;
	c = 0;
	x = 0;
	a = data->player.angle - FOV / 2;
	raycasting_part_two(data, a, x, c);
	sort_sprites(data);
	while (i < data->sprite_counter)
	{
		drow_sprites(data, data->sprites[i]);
		i++;
	}
	if (!data->flag_save)
		mlx_put_image_to_window(data->mlx, data->window, data->bas.ptr, 0, 0);
}
