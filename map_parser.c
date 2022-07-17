/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:39:13 by tasian            #+#    #+#             */
/*   Updated: 2021/02/23 15:39:15 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "get_next_line_bonus.h"

void	parse_sprites(char *line, t_data *data)
{
	char **file;

	if (line[1] != ' ')
	{
		write(1, "Error\n map processing successfully failed\n", 42);
		exit(0);
	}
	file = ft_split(line + 1, ' ');
	if ((file[1] != NULL))
	{
		write(1, "Error\n map processing successfully failed\n", 42);
		exit(0);
	}
	if (!(data->sauce.sp = ft_strdup(file[0])))
		error_parser(4);
	data->checker_map++;
	free(file[0]);
	free(file);
}

void	parse_textures(char *line, t_data *data)
{
	char	**file;

	if (line[2] != ' ')
		error_parser(7);
	file = ft_split(line + 2, ' ');
	if ((file[1] != NULL))
		error_parser(7);
	parse_textures_2(line, file, data);
	data->checker_map++;
	free(file[0]);
	free(file);
}

void	parse_color(char *line, t_data *data, char flag)
{
	char	**text;

	if (!(text = skips(line)))
		error_parser(7);
	if ((!text[0]) || !(text[0] = color_trim(text[0], ",")))
		error_parser(7);
	if ((!text[1]) || !(text[1] = color_trim(text[1], ",")))
		error_parser(7);
	if ((!text[2]) || (text[2][3] && text[2][3] == ','))
		error_parser(7);
	if ((data->sauce.ceiling && flag) || (data->sauce.floor && !flag))
		error_parser(7);
	if (text[3])
		error_parser(2);
	if (flag)
		data->sauce.ceiling = create_trgb(atoi_rgb(text[0]),\
		atoi_rgb(text[1]), atoi_rgb(text[2]));
	if (!flag)
		data->sauce.floor = create_trgb(atoi_rgb(text[0]),\
		atoi_rgb(text[1]), atoi_rgb(text[2]));
	data->checker_map++;
	free(text[2]);
	free(text[1]);
	free(text[0]);
	free(text);
}

void	parse_resolution(char *line, t_data *data)
{
	char	**resolution;
	int		max_size_x;
	int		max_size_y;

	mlx_get_screen_size(&max_size_x, &max_size_y);
	resolution = ft_split(line, ' ');
	if (data->size_map_x || data->size_map_y)
		error_parser(7);
	if (!(data->size_map_x = (float)ft_atoi(resolution[0])))
		error_parser(2);
	if (!(data->size_map_y = (float)ft_atoi(resolution[1])))
		error_parser(2);
	if (data->size_map_x < 50 || data->size_map_y < 50 || resolution[2])
		error_parser(2);
	parse_resolution_norme(data, max_size_x, max_size_y);
	data->map.ptr = mlx_new_image(data->mlx, MAX_SIZE, \
													MAX_SIZE);
	data->map.addr = mlx_get_data_addr(data->map.ptr, &data->map.bpp, \
										&data->map.length, &data->map.endian);
	data->checker_map++;
	data->x_buffer = malloc(sizeof(float) * data->size_map_x);
	free(resolution[1]);
	free(resolution[0]);
	free(resolution);
}

void	main_parser(t_data *data, char *line, int *counter)
{
	if (line[0] == 'R' && line[1] == ' ')
		parse_resolution(line + 2, data);
	else if ((line[0] == 'N' && line[1] == 'O') || \
	(line[0] == 'S' && line[1] == 'O') || \
	(line[0] == 'W' && line[1] == 'E') || \
	(line[0] == 'E' && line[1] == 'A'))
		parse_textures(line, data);
	else if (line[0] == 'S')
		parse_sprites(line, data);
	else if (line[0] == 'F' && line[1] == ' ')
	{
		parse_color(line + 1, data, 0);
		data->sauce.floor += data->sauce.floor == 0 ? 1 : 0;
	}
	else if (line[0] == 'C' && line[1] == ' ')
		parse_color(line + 1, data, 1);
	else if (data->checker_map == 8)
		draw_map(data, line, (*counter)++);
	else if (line[0] != '\0' || data->checker_map > 8)
		error_parser(2);
}
