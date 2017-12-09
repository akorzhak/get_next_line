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
	int		f;

	f = open(argv[1], O_RDONLY);
	get_next_line(f, &line);
	printf("%s\n", line);
	get_next_line(f, &line);
	printf("%s\n", line);
	get_next_line(f, &line);
	printf("%s\n", line);
	get_next_line(f, &line);
	printf("%s\n", line);
	get_next_line(f, &line);
	printf("%s\n", line);
	get_next_line(f, &line);
	printf("%s\n", line);
//	system("leaks a.out");
	return (0);
}
