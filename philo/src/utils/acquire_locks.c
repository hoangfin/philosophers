/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acquire_locks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:20:03 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/12 19:53:20 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	acquire_locks(pthread_mutex_t *mutexes[], int mutex_count)
{
	int	i;

	i = 0;
	while (i < mutex_count)
	{
		if (pthread_mutex_lock(mutexes[i]) != 0)
		{
			i--;
			while (i > 0)
				pthread_mutex_unlock(mutexes[i--]);
			return (-1);
		}
		i++;
	}
	return (0);
}
