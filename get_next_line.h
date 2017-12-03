/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:49:06 by akorzhak          #+#    #+#             */
/*   Updated: 2017/11/29 14:49:09 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"

# define BUFF_SIZE 32

typedef struct		s_stor
{
	char			*buff;
	int				fd;	
	size_t			nb;
	struct s_stor	*next;
	struct s_stor	*prev;
}					t_stor;

int		get_next_line(const int fd, char **line);

#endif
