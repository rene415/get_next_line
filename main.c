/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:31:26 by rramirez          #+#    #+#             */
/*   Updated: 2017/05/26 13:32:15 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*file;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &file))
		{
			printf("%s\n", file);
			free(file);
		}
		close(fd);
	}
	return (0);
}
