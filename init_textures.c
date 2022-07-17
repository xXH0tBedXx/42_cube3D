/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:53:58 by tasian            #+#    #+#             */
/*   Updated: 2021/03/04 18:53:59 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	init_textures2(t_data *data)
{
	if (!(data->no.ptr = mlx_xpm_file_to_image(data->mlx, data->sauce.no, \
	&data->no.sizex, &data->no.sizey)))
		error_parser(2);
	data->no.addr = mlx_get_data_addr(data->no.ptr, &data->no.bpp, \
	&data->no.length, &data->no.endian);
	if (!(data->ea.ptr = mlx_xpm_file_to_image(data->mlx, data->sauce.ea, \
	&data->ea.sizex, &data->ea.sizey)))
		error_parser(2);
	data->ea.addr = mlx_get_data_addr(data->ea.ptr, &data->ea.bpp, \
	&data->ea.length, &data->ea.endian);
	if (!(data->we.ptr = mlx_xpm_file_to_image(data->mlx, data->sauce.we, \
	&data->we.sizex, &data->we.sizey)))
		error_parser(2);
	data->we.addr = mlx_get_data_addr(data->we.ptr, &data->we.bpp, \
	&data->we.length, &data->we.endian);
}
