/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_name_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:55:42 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/15 21:54:12 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "types_bonus.h"

static void	reverse(char *str)
{
	int		i;
	int		mid;
	int		length;
	char	temp;

	length = 0;
	while (str[length] != '\0')
		length++;
	if (length < 2)
		return ;
	mid = (length - 1) / 2;
	i = 0;
	while (i <= mid)
	{
		temp = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = temp;
		i++;
	}
}

void	set_name(char *buf, const char *name, int id)
{
	char	temp[8 * sizeof(int) + 1];
	int		i;

	i = 0;
	while (id > 0)
	{
		temp[i++] = (id % 10) + '0';
		id = id / 10;
	}
	temp[i] = '\0';
	reverse(temp);
	while (*name != '\0')
	{
		*buf = *name;
		buf++;
		name++;
	}
	i = 0;
	while (temp[i] != '\0')
	{
		*buf = temp[i++];
		buf++;
	}
	*buf = '\0';
}
