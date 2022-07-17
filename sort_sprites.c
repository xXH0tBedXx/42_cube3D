/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 00:32:11 by tasian            #+#    #+#             */
/*   Updated: 2021/03/05 00:32:12 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	draw_pixel(char *line, int counter, int number, t_data *data)
{
	if (number > MAX_SIZE || counter > MAX_SIZE)
		error_parser(5);
	if (*(line + counter) == '0')
		mlx_put_pixel(&data->map, counter, number, data->sauce.floor);
	if (*(line + counter) == '1')
		mlx_put_pixel(&data->map, counter, number, WCL);
	if (*(line + counter) == '2')
		mlx_put_pixel(&data->map, counter, number, SCL);
	if (*(line + counter) == '2')
		manager_sprites(data, counter, number);
}

void	find_dist(t_data *s)
{
	int i;

	i = 0;
	while (i < s->sprite_counter)
	{
		s->sprites[i].dist = sqrt(pow(s->sprites[i].x - s->player.posx, 2)
		+ pow(s->sprites[i].y - s->player.posy, 2));
		i++;
	}
}

void	sort_sprites(t_data *s)
{
	int			i;
	int			j;
	t_sprite	tmp;

	j = 0;
	i = 0;
	find_dist(s);
	while (i < s->sprite_counter)
	{
		j = i;
		while (j < s->sprite_counter - 1)
		{
			if (s->sprites[j].dist < s->sprites[j + 1].dist)
			{
				tmp = s->sprites[j];
				s->sprites[j] = s->sprites[j + 1];
				s->sprites[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
