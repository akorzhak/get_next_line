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

int 	get_next_line(const int fd, char **line)
{
	int				r;
	static t_list	*list;

	list = NULL;
	while (list)
	{
		if (list->content_size == fd)
		{
			while (list->*content != '\n' && list->content)
				*line++ = *content++
		}
		list = list->next;
	}
	list = ft_lstnew(read(fd, line), BUF_SIZE);
	list->content_size = fd;
	
	line = ft_strnew(BUF_SIZE);
	r = read(fd, line)

}
