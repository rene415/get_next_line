/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:18:40 by rramirez          #+#    #+#             */
/*   Updated: 2017/03/11 17:04:42 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft/libft.h"

#define BUFF_SIZE		1
#define TRUE			1
#define	FALSE			0

int		get_next_line(const int	fd, char ** line);

#endif
