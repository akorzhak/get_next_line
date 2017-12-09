/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:48:46 by akorzhak          #+#    #+#             */
/*   Updated: 2017/11/29 14:48:49 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_realloc(void *arr, size_t size)
{
	void *new;

	if (ft_strlen(arr) == size)
		return (arr);
	if (!(new = ft_memalloc(size)))
		return (0);
	if (arr)
	{
		if (ft_strlen(arr) > size)
  			ft_memcpy(new, arr, size);
  		else
  			ft_memcpy(new, arr, ft_strlen(arr));
 		free(arr);
	}
 	return (new);
} 

int		get_line(char *buff, char **line)
{
	size_t i;
	char  *n;

	if (!buff)
	{
		free(buff);
		free(*line);
		return (0);
	}
	n = ft_memchr(buff, '\n', ft_strlen(buff));
	i = n - buff;
//	printf("%lu\n", i);
	if (!(*line = ft_realloc(*line, (ft_strlen(*line) + i + 1))))
		return (-1);
	ft_strncat(*line, buff, i);
//	printf("%s\n", *line);
//	printf("%s\n", buff);
//	printf("BUFFER: %s\n", buff);	
	ft_bzero(buff, ++i);
//	printf("%s\n", buff);	
	ft_memmove(buff, n + 1, ft_strlen(n + 1));
//	printf("BUFFER1: %s\n", buff);	
	ft_bzero(&buff[ft_strlen(buff) - i], ft_strlen(buff) - ft_strlen(&buff[ft_strlen(buff) - i])); // ????
//	printf("%s\n", list->buff);
//	printf("BUFFER2: %s\n", buff);
	return (1);
}

t_dlist		*get_list(int fd, t_dlist *list, char flag)
{
	t_dlist *new;

	while (list && list->prev && flag == '-')
		list = list->prev;
	if (!list || flag == '+')
	{
		if ((new = (t_dlist *)ft_memalloc(sizeof(t_dlist))) == 0)
			return (0);
		new->fd = fd;
		new->buff = ft_strnew(BUFF_SIZE);
		new->next = 0;
		new->prev = list;
		(list) ? (list->next = new) : 0;
		return (new);
	}
	while (list->fd != fd && list->next)
		list = list->next;
	if (list->fd == fd)
		return (list);
	return (get_list(fd, list, '+')); //if fd wasn't found, pass the last el
}

int  get_next_line(const int fd, char **line)
{
	static t_dlist	*list;
	int				c;

	if (BUFF_SIZE < 1 || fd == -1 || !line)
		return (-1);
	if (!(list = get_list(fd, list, '-')))
		return (-1);
	if ((list->buff) && !ft_memchr(list->buff, '\n', ft_strlen(list->buff)))
	{
		*line = ft_strnew(ft_strlen(list->buff));
		ft_strcpy(*line, list->buff);
	}
	else //if (!list->buff)
		*line = ft_strnew(BUFF_SIZE);
	while (!ft_memchr(list->buff, '\n', BUFF_SIZE))
	{
		if ((c = read(fd, list->buff, BUFF_SIZE)) == -1)
			return (-1);
		if (!ft_memchr(list->buff, '\n', BUFF_SIZE)) //ft_strlen(buff)
    	{
			if (!(*line = ft_realloc(*line, (ft_strlen(*line) + c + 1))))
	 			return (-1);
			ft_strcat(*line, list->buff);
		}
	}
	return (get_line(list->buff, line));
}
