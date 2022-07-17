/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:00:41 by tasian            #+#    #+#             */
/*   Updated: 2020/11/11 17:30:45 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int unsigned_n;

	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n < 0)
		unsigned_n = n * (-1);
	else
		unsigned_n = n;
	if (unsigned_n > 9)
		ft_putnbr_fd(unsigned_n / 10, fd);
	ft_putchar_fd(unsigned_n % 10 + 48, fd);
}
