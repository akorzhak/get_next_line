/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:36:32 by akorzhak          #+#    #+#             */
/*   Updated: 2017/12/06 12:37:02 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int		main(int argc, char **argv)
{
	char	*line;
	get_next_line(open(argv[1], O_RDONLY), &line);
	printf("%s\n", line);
	return (0);
}
