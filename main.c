/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:34:19 by tasian            #+#    #+#             */
/*   Updated: 2021/03/06 00:28:56 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	backslash_zero(char sym)
{
	static int	flag;

	if (!flag && sym != '\0')
		flag = 1;
	if (flag == 1 && sym == '\0')
		flag = 2;
	if (flag == 2 && sym != '\0')
		error_parser(5);
}

char	validate_save(char *name, char *save, char *flag)
{
	int		counter;

	counter = 0;
	while (name[counter] == save[counter])
	{
		if (name[counter] == '\0' && save[counter] == '\0')
		{
			*flag = '1';
			return (0);
		}
		counter++;
	}
	return (1);
}

char	validate_name(char *name)
{
	name = ft_strrchr(name, '.');
	if (ft_strcmp(name, ".cub"))
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_data	data;

	data.checker_map = 0;
	data.sprite_counter = 0;
	data.mlx = mlx_init();
	if (argc == 2)
	{
		if (validate_name(argv[1]))
			error_parser(1);
		validate_file(&data, argv[1]);
	}
	else if (argc == 3)
	{
		if (validate_name(argv[1]) \
			|| validate_save(argv[2], "--save", &data.flag_save))
			error_parser(1);
		validate_file(&data, argv[1]);
	}
	else
		error_parser(6);
	mlx_hook(data.window, 17, 0, closed, &data);
	mlx_loop(data.mlx);
	return (0);
}
