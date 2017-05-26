/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:18:53 by rramirez          #+#    #+#             */
/*   Updated: 2017/05/25 17:44:27 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_len(char *buff_store, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (buff_store[i] != '\0' && buff_store[i] != c)
	{
		i++;
		len++;
	}
	return (len + 1);
}

int		store_to_line(char **buff_store, char **line)
{
	char *tmpr;
	int len;

	tmpr = NULL;
	if(ft_strlen(*buff_store))
	{
		len = ft_len(*buff_store, '\n');
		if (strchr(*buff_store, '\n'))
		{
			*line = ft_strsub(*buff_store, 0, len);
			tmpr = ft_strdup(*buff_store + len);
			free(*buff_store);
			*buff_store = tmpr;
			return (1);
		}
		*line = strdup(*buff_store);
		free(*buff_store);
		*buff_store = NULL;
		return (1);
	}
	return (0);
}

char 	*buff_read(char *buff_store, char *buff, int fd)
{
	size_t			ret;
	char			*tmp;

	ret = 0;
	tmp = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!buff_store)
			buff_store = ft_strnew(1);
		tmp = ft_strjoin(buff_store, buff);
		free(buff_store);
		buff_store = tmp;
		if (ft_strchr(buff_store, '\n'))
			break;
	}
	return (buff_store);
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*buff_store;
	char			*tmpr;

//	static int		x = 0;
	tmpr = NULL;
	if (fd == -1 || BUFF_SIZE <= 0 || !line)
		return (-1);
	tmpr = buff_read(buff_store, buff, fd);
	buff_store = tmpr;
	if (buff_store == NULL)
		return (0);
	if (store_to_line(&buff_store, line))
		return (1);
	return (0);
}
