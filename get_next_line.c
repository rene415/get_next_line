/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:18:53 by rramirez          #+#    #+#             */
/*   Updated: 2017/05/19 18:56:57 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_len(char *buff, char c)
{
	int i;
	int	len;

	i = 0;
	len =0;
	while (buff[i] != '\0' && buff[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}


char 	*buff_read(char *buff_store, char *buff, int fd, char *tmpr)
{
	size_t			ret;
//	char			*tmpr;

	ret = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!buff_store)
		buff_store = ft_strnew(1);
		tmpr = ft_strjoin(buff_store, buff);
		if (ft_strchr(buff_store, '\n'))
		{
			printf("%s", tmpr);
			break;
		}
		free(buff_store);
	}
	return (tmpr);
}
/**
 * Starting to change things... check the buff */
int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*buff_store;
	char			*tmpr;
	int				len;

	tmpr = NULL;
	if (fd == -1 || BUFF_SIZE <= 0 || !line)
		return (-1);
	buff_read(buff_store, buff, fd, tmpr);
	buff_store = tmpr;
	if (buff_store == NULL)
		return (0);
	if(ft_strlen(tmpr))
	{
		len = ft_len(buff, '\n');
		if (strchr(buff, '\n'))
		{
			*line = ft_strsub(buff_store,0, len);
			tmpr = ft_strdup(buff_store);
			free(buff_store);
			return (1);
		}
		return (0);
	}
	return (0);
}
