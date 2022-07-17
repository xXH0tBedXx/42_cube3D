/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:26:28 by tasian            #+#    #+#             */
/*   Updated: 2020/11/27 21:27:12 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*save_rest_buff(char *line)
{
	int		index1;
	int		index2;
	char	*save_line;

	index1 = 0;
	index2 = 0;
	while (line[index1] && line[index1] != '\n')
		index1++;
	if (!(line[index1]))
	{
		free(line);
		return (NULL);
	}
	if (!(save_line = malloc(sizeof(char) * (ft_strlen(line) - index1) + 1)))
		return (NULL);
	index1++;
	while (line[index1])
		save_line[index2++] = line[index1++];
	save_line[index2] = '\0';
	free(line);
	return (save_line);
}

char	*copy_one_line(char *line)
{
	int		index;
	char	*copy_line;

	index = 0;
	if (!line)
		return (NULL);
	while (line[index] && line[index] != '\n')
		index++;
	if (!(copy_line = malloc(sizeof(char) * (index + 1))))
		return (NULL);
	index = 0;
	while (line[index] && line[index] != '\n')
	{
		copy_line[index] = line[index];
		index++;
	}
	copy_line[index] = '\0';
	return (copy_line);
}

int		gnl(int fd, char **line, char **str_to_save)
{
	char		*buff;
	int			was_read;
	char		*tmp;

	was_read = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((checker_n(*str_to_save)) && was_read != 0)
	{
		if ((was_read = read(fd, buff, BUFFER_SIZE)) < 0)
		{
			free(buff);
			return (-1);
		}
		buff[was_read] = '\0';
		tmp = *str_to_save;
		*str_to_save = ft_strjoin(*str_to_save, buff);
		free(tmp);
	}
	free(buff);
	*line = copy_one_line(*str_to_save);
	*str_to_save = save_rest_buff(*str_to_save);
	return (was_read == 0 ? 0 : 1);
}

t_gnl	*new_linked_list_el(int fd)
{
	t_gnl *new;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	new->fd = fd;
	new->remnant = NULL;
	new->next = NULL;
	return (new);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;

	if (fd < 0)
		return (-1);
	if (head == NULL)
		head = new_linked_list_el(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_linked_list_el(fd);
		tmp = tmp->next;
	}
	return (gnl(tmp->fd, line, &tmp->remnant));
}
