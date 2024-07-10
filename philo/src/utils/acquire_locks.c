/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acquire_locks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:20:03 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/09 14:40:58 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>

int	acquire_locks(
	pthread_mutex_t *mutexes[],
	int num_of_mutexes,
	void *data,
	int (*fn)(void *data)
)
{
	int	i;

	i = 0;
	while (i < num_of_mutexes)
	{
		if (pthread_mutex_lock(mutexes[i]) != 0)
		{
			write(2, "acquire_locks: Failed to lock a mutex\n", 38);
			i--;
			while (i > 0)
				pthread_mutex_unlock(mutexes[i--]);
			return (-1);
		}
		if (fn != NULL && fn(data) == -1)
		{
			while (i > 0)
				pthread_mutex_unlock(mutexes[i--]);
			return (-1);
		}
		i++;
	}
	return (0);
}
