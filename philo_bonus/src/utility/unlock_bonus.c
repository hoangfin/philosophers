/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlock_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:20:03 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/30 22:44:18 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils_bonus.h"

static size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

void	unlock(pthread_mutex_t *mutex, const char *err_msg)
{
	if (pthread_mutex_unlock(mutex) != 0)
	{
		write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
		write(STDERR_FILENO, "\n", 1);
		exit(1);
	}
}
