/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 10:21:54 by rramirez          #+#    #+#             */
/*   Updated: 2017/02/18 10:22:01 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_spaces(int str)
{
	unsigned char s;

	s = (unsigned char)str;
	if (s == '\t' || s == '\r' || s == '\v' || s == '\f' || s == '\n' ||
		s == ' ')
		return (1);
	else
		return (0);
}