/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:18:53 by rramirez          #+#    #+#             */
/*   Updated: 2017/03/11 17:04:37 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char  saving()
{

}

/**
 * Starting to change things... check the buff */
int		get_next_line(const int fd, char **file)
{
	static char	*buff_store[4096];
	char		buff[BUFF_SIZE + 1];
	int 		ret;

	if (fd == -1 || BUFF_SIZE <= 0 || !line)
		return (-1);
	while (ret = read(fd, buff, BUFF_SIZE))
}
