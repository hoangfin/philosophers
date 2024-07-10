/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_locks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:30:45 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/09 23:08:13 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>

int	release_locks(pthread_mutex_t *mutexes[], int num_of_mutexes)
{
	int	i;
	int	status;

	i = num_of_mutexes - 1;
	status = 0;
	while (i >= 0)
	{
		if (pthread_mutex_unlock(mutexes[i]) != 0)
		{
			status = -1;
			write(2, "release_locks: Failed to unlock a mutex\n", 40);
		}
		i--;
	}
	if (status == -1)
		return (-1);
	return (0);
}
