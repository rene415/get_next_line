/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:18:53 by rramirez          #+#    #+#             */
/*   Updated: 2017/05/16 20:11:25 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char 	buff_read(char *buff_store, char *buff, int fd)
{
	size_t			ret;
	char			*tmpr;

	ret = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!buff_store)
		buff_store = ft_strnew(1);
		tmpr = ft_strjoin(buff_store, buff);
		free(buff_store);
		buff_store = tmpr;
		if (ft_strchr(buff_store, '\n'))
		{
			printf("%s", tmpr);
			//return (*tmpr)
			break;
		}
	}
	return (*tmpr);
}
/**
 * Starting to change things... check the buff */
int		get_next_line(const int fd, char **file)
{
	char			buff[BUFF_SIZE + 1];
	static char		*buff_store;
	// size_t			ret;
	// char			*tmpr;

	// ret = 0;
	if (fd == -1 || BUFF_SIZE <= 0 || !file)
		return (-1);
	buff_read(buff_store, buff, fd);
	/*while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!buff_store)
		buff_store = ft_strnew(1);
		tmpr = ft_strjoin(buff_store, buff);
		free(buff_store);
		buff_store = tmpr;
		if (ft_strchr(buff_store, '\n'))
		{
			printf("%s", tmpr);
			break;
		}
	}
	*/
	if (buff_store == NULL)
		return (0);
	if(ft_strlen(tmpr))
	{

	}
	return (0);
}
