/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 00:17:24 by tasian            #+#    #+#             */
/*   Updated: 2021/03/04 18:56:45 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_sprite	*list_to_array(t_data *data)
{
	t_list		*tmp;
	t_sprite	*arr;
	int			count;

	arr = malloc(sizeof(t_sprite) * data->sprite_counter);
	count = 0;
	while (count < data->sprite_counter)
	{
		arr[count] = *(t_sprite *)data->list->content;
		free(data->list->content);
		tmp = data->list->next;
		free(data->list);
		data->list = tmp;
		count++;
	}
	return (arr);
}

void		pray_the_norme(t_data *data)
{
	validate_map(data);
	init_textures(data);
	if (!data->flag_save)
		data->window = mlx_new_window(data->mlx, data->size_map_x, \
								data->size_map_y, "cub3D");
	data->sprites = list_to_array(data);
}

void		validate_file(t_data *data, char *map_name)
{
	int			fd;
	char		*line;
	int			counter;
	char		ret;

	ret = 1;
	counter = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error_parser(3);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		main_parser(data, line, &counter);
		free(line);
	}
	if (!data->player.posx || !data->player.posy)
		error_parser(5);
	pray_the_norme(data);
	raycasting(data);
	if (data->flag_save)
		save_image_as_bmp(data, "save");
	mlx_hook(data->window, 2, 0, button_pressed, data);
	close(fd);
}
