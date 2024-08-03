/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlock_sem_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:20:03 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/02 21:45:04 by hoatran          ###   ########.fr       */
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

void	unlock_sem(sem_t *semaphore, const char *err_msg)
{
	if (sem_post(semaphore) != 0)
	{
		write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
		write(STDERR_FILENO, "\n", 1);
		exit(1);
	}
}
