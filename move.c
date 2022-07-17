/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 02:57:53 by tasian            #+#    #+#             */
/*   Updated: 2021/03/04 18:57:28 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	parse_textures_2(char *line, char **file, t_data *data)
{
	if (line[0] == 'N' && line[1] == 'O' && !data->sauce.no && cmp_xpm(line))
	{
		if (!(data->sauce.no = ft_strdup(file[0])))
			error_parser(4);
	}
	else if (line[0] == 'S' && line[1] == 'O' \
	&& !data->sauce.so && cmp_xpm(line))
	{
		if (!(data->sauce.so = ft_strdup(file[0])))
			error_parser(4);
	}
	else if (line[0] == 'W' && line[1] == 'E' \
	&& !data->sauce.we && cmp_xpm(line))
	{
		if (!(data->sauce.we = ft_strdup(file[0])))
			error_parser(4);
	}
	else if (line[0] == 'E' && line[1] == 'A' \
	&& !data->sauce.ea && cmp_xpm(line))
	{
		if (!(data->sauce.ea = ft_strdup(file[0])))
			error_parser(4);
	}
	else
		error_parser(7);
}

void	move(t_data *data, double x, int y)
{
	if (y)
	{
		if (mlx_get_pixel_color(data, data->player.posx +\
		(cos(data->player.angle) * 2 * (-x)), data->player.posy +\
		(sin(data->player.angle) * 2 * (-x)), 0) == WCL)
			return ;
		data->player.posx = data->player.posx + (cos(data->player.angle) *\
		(-x));
		data->player.posy = data->player.posy + (sin(data->player.angle) *\
		(-x));
	}
	else
	{
		if (mlx_get_pixel_color(data, data->player.posx + \
		(cos(data->player.angle + 1.5708) * 2 * x), data->player.posy\
		+ (sin(data->player.angle + 1.5708) * 2 * x), 0) == WCL)
			return ;
		data->player.posx = data->player.posx + \
		(cos(data->player.angle + 1.5708) * x);
		data->player.posy = data->player.posy + \
		(sin(data->player.angle + 1.5708) * x);
	}
}

int		button_pressed(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->window);
		exit(0);
	}
	if (key == 123)
		data->player.angle -= 0.09375;
	if (key == 124)
		data->player.angle += 0.09375;
	if (key == 13)
		move(data, -0.15625, 1);
	if (key == 0)
		move(data, -0.15625, 0);
	if (key == 1)
		move(data, 0.15625, 1);
	if (key == 2)
		move(data, 0.15625, 0);
	raycasting(data);
	return (0);
}
