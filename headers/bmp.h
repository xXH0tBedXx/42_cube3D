/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:40:10 by tasian            #+#    #+#             */
/*   Updated: 2021/03/04 21:40:44 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H
# include "libft.h"
# include <fcntl.h>
# define BMP_EXTN			".bmp"
# define BMP_IDENTIFIER		"BM"
# define BMP_BYTEPERPIXEL	4
# define BMP_SIZEOFHEADER	54
# define BMP_SIZEOFINFO		40
# define BMP_RESERVED		0
# define BMP_PLANES			1
# define BMP_BITPERPIXEL	32
# define BMP_COMPRESSION	0
# define BMP_SIZEIMAGE		0
# define BMP_XPELSPERMETER	0
# define BMP_YPELSPERMETER	0
# define BMP_CLRUSED		0
# define BMP_CLRIMPORTANT	0

typedef struct	s_bitmapfileheader
{
	char			type[2];
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offset;
}				t_bitmapfileheader;

typedef struct	s_bitmapinfo
{
	int		size;
	int		width;
	int		height;
	short	planes;
	short	bitcount;
	int		compression;
	int		sizeimage;
	int		xpelspermeter;
	int		ypelspermeter;
	int		clrused;
	int		clrimportant;
}				t_bitmapinfo;

/*
** Sructure for setting/storage bmpfile image
*/
typedef struct	s_bmpfile
{
	t_bitmapfileheader	fileheader;
	t_bitmapinfo		info;
	char				*data;
}				t_bmpfile;

int				ft_write_bmp(int fd, t_bmpfile *bitmap);

#endif
