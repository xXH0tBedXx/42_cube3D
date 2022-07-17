/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:21:10 by tasian            #+#    #+#             */
/*   Updated: 2021/03/04 23:22:18 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "bmp.h"

static void		set_bmp_info_from_image(t_bitmapinfo *info, t_data *data)
{
	info->size = BMP_SIZEOFINFO;
	info->width = data->size_map_x;
	info->height = -data->size_map_y;
	info->planes = BMP_PLANES;
	info->bitcount = BMP_BITPERPIXEL;
	info->compression = BMP_COMPRESSION;
	info->sizeimage = BMP_SIZEIMAGE;
	info->xpelspermeter = BMP_XPELSPERMETER;
	info->ypelspermeter = BMP_YPELSPERMETER;
	info->clrused = BMP_CLRUSED;
	info->clrimportant = BMP_CLRIMPORTANT;
}

static void		set_bmp_data_from_image(t_bmpfile *bmp, t_data *data)
{
	ft_memcpy(bmp->fileheader.type, BMP_IDENTIFIER, sizeof(BMP_IDENTIFIER));
	bmp->fileheader.size = data->size_map_x * data->size_map_y * \
									BMP_BYTEPERPIXEL + BMP_SIZEOFHEADER;
	bmp->fileheader.reserved = 0;
	bmp->fileheader.offset = BMP_SIZEOFHEADER;
	set_bmp_info_from_image(&bmp->info, data);
	bmp->data = data->bas.addr;
}

void			save_image_as_bmp(t_data *data, const char *name)
{
	int			fd;
	char		*bmp_file_name;
	t_bmpfile	bmp_data;

	if (!(bmp_file_name = ft_strjoin(name, BMP_EXTN)))
		exit(0);
	if ((fd = open(bmp_file_name, O_CREAT | O_WRONLY | O_TRUNC,
											S_IRUSR | S_IWUSR)) < 0)
		exit(0);
	free(bmp_file_name);
	set_bmp_data_from_image(&bmp_data, data);
	if (!(ft_write_bmp(fd, &bmp_data)))
		exit(0);
	close(fd);
	exit(0);
}
