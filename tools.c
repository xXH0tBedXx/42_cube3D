/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 02:43:47 by tasian            #+#    #+#             */
/*   Updated: 2021/02/28 02:56:57 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/cubed.h"

int				cmp_xpm(char *line)
{
	line = ft_strrchr(line, '.');
	if (ft_strcmp(line, ".xpm"))
		return (0);
	return (1);
}

char			ft_strcmp(char *string1, char *string2)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (flag == 0)
	{
		if (string1[i] > string2[i])
			flag = 1;
		else if (string1[i] < string2[i])
			flag = -1;
		if (string1[i] == '\0')
			break ;
		i++;
	}
	return (flag);
}

unsigned int	mlx_get_pixel_color(t_data *data, int x, int y, int flag)
{
	unsigned int	color;
	char			*dst;

	dst = NULL;
	if (flag == 1)
		dst = data->ea.addr + (y * data->ea.length + x * (data->ea.bpp / 8));
	else if (flag == 2)
		dst = data->we.addr + (y * data->we.length + x * (data->we.bpp / 8));
	else if (flag == 3)
		dst = data->so.addr + (y * data->so.length + x * (data->so.bpp / 8));
	else if (flag == 4)
		dst = data->no.addr + (y * data->no.length + x * (data->no.bpp / 8));
	else if (flag == 5)
		dst = data->sprite.addr + (y * data->sprite.length + \
				x * (data->sprite.bpp / 8));
	else
		dst = data->map.addr + (y * data->map.length + x * (data->map.bpp / 8));
	color = *(unsigned int*)dst;
	return (color);
}

int				create_trgb(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
	{
		write(1, "Error\nwrong colors\n", 19);
		exit(0);
	}
	return (r << 16 | g << 8 | b);
}

void			mlx_put_pixel(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}
