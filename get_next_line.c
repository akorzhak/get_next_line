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

int		get_line(int fd, char *buff, char *line, int c)
{
	size_t i;
	char  *n;

	if (!*buff || ft_strlen(buff) < BUFF_SIZE) //??? return (line)?
	{
		if (!(line = ft_strjoin(line, buff)))
			return (-1);
    //free(line);
		return (0);
	}
	n = ft_memchr(buff, '\n', BUFF_SIZE);
	i = n - buff;
	if (!(line = ft_realloc(line, (ft_strlen(line) + i + 1))))
		return (-1);
	ft_strncat(line, buff, i);
	ft_bzero(buff, i + 1);
	ft_memmove(buff, n, ft_strlen(n));
	return (1);
}

t_dlist		*get_list(int fd, t_dlist *list, char flag)
{
	t_dlist *new;

	//printf("%c\n", flag);
//	printf("--%d\n", fd);
	while (list && list->prev && flag == '-')
		list = list->prev;
	if (!list || flag == '+')
	{
		if ((new = (t_dlist *)ft_memalloc(sizeof(t_dlist))) == 0)
			return (0);
		new->fd = fd;
		//printf("!!\n");
		//printf("%d\n", new->fd);
		new->buff = ft_strnew(BUFF_SIZE);
		new->buff = "Hello";
		//printf("%s\n", new->buff);
		new->next = 0;
		new->prev = list;
		return (new);
	}
	//printf("dfgdf\n");
	while (list->fd != fd && list->next)
		list = list->next;
	if (list->fd == fd)
		return (list);
	return (get_list(fd, list, '+')); //if fd wasn't found, pass the last el
}

int  get_next_line(const int fd, char **line)
{
	static t_dlist *list = 0;
	char   flag;
	int    c;

	flag = '-';
//	printf("%c\n", flag);
	if (BUFF_SIZE < 1 || fd == -1 || !line)
		return (-1);
	if (!(list = get_list(fd, list, flag)))
    	return (-1);
  //  printf("%c\n", flag);
	if (*(list->buff) && !ft_memchr(list->buff, '\n', BUFF_SIZE))
	{
//		printf("%c\n", flag);
		*line = ft_strnew(ft_strlen(list->buff));
		*line = "Hello";
		ft_strcpy(*line, list->buff);
	}
	else if (!(*(list->buff)))
		*line = ft_strnew(BUFF_SIZE);
//	printf("%c\n", flag);
	while (!ft_memchr(list->buff, '\n', BUFF_SIZE))
	{
		if ((c = read(fd, list->buff, BUFF_SIZE)) == -1)
			return (-1); //to add list->buff[BUFF_SIZE] = '\0';
		if (!ft_memchr(list->buff, '\n', BUFF_SIZE))
    	{
			if (!(line = ft_realloc(*line, (ft_strlen(*line) + c + 1))))
	 			return (-1);
			ft_strcat(*line, list->buff);
	//  if ((line = ft_strjoin(line, list->buff)) == 0)
      //  return (-1);
		//	if (c < BUFF_SIZE)
      //break ;
		}
	}
	return (get_line(fd, list->buff, *line, c));
}
