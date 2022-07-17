/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 00:37:07 by tasian            #+#    #+#             */
/*   Updated: 2021/03/05 12:16:06 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	manager_sprites(t_data *s, int x, int y)
{
	t_sprite	*tmp;
	t_list		*xuy;

	(tmp = malloc(sizeof(t_sprite)));
	if (!tmp)
		error_parser(4);
	tmp->x = x + 0.5;
	tmp->y = y + 0.5;
	if (!(xuy = ft_lstnew(tmp)))
		error_parser(4);
	ft_lstadd_front(&s->list, xuy);
	s->sprite_counter++;
}

void	parse_resolution_norme(t_data *data, int x, int y)
{
	if (data->flag_save && \
	(data->size_map_x > MAX_SIZE || data->size_map_y > MAX_SIZE))
		error_parser(7);
	if (!data->flag_save)
	{
		if (x < data->size_map_x)
			data->size_map_x = x;
		if (y < data->size_map_y)
			data->size_map_y = y;
	}
}

int		closed(t_data *data, int flag)
{
	if (flag)
	{
		mlx_destroy_window(data->mlx, data->window);
		exit(0);
	}
	return (0);
}

void	error_parser2(int flag)
{
	if (flag == 4)
	{
		write(2, "Error\nsomething is wrong with memory allocation\n", 47);
		exit(0);
	}
	else if (flag == 5)
	{
		write(2, "Error\nwrong map\n", 16);
		exit(0);
	}
	else if (flag == 6)
	{
		write(2, "Error\ninvalid number of arguments\n", 35);
		exit(0);
	}
	else if (flag == 7)
	{
		write(2, "Error\nwrong file\n", 17);
		exit(0);
	}
}

void	error_parser(int flag)
{
	if (flag == 1)
	{
		write(2, "Error\ninvalid map name\n", 24);
		exit(0);
	}
	else if (flag == 2)
	{
		write(2, "Error\nwrong file\n", 17);
		exit(0);
	}
	else if (flag == 3)
	{
		write(2, "Error\nmap file does not open\n", 30);
		exit(0);
	}
	else
		error_parser2(flag);
}
