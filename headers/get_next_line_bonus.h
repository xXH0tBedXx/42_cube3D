/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:27:57 by tasian            #+#    #+#             */
/*   Updated: 2021/03/04 21:39:05 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "cubed.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

typedef struct		s_gnl
{
	int				fd;
	char			*remnant;
	struct s_gnl	*next;
}					t_gnl;
int					get_next_line(int fd, char **line);
int					checker_n(char *str);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(const char *s1, const char *s2);
#endif
