/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_locks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:30:45 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/12 19:54:17 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	release_locks(pthread_mutex_t *mutexes[], int mutex_count)
{
	int	i;
	int	status;

	i = mutex_count - 1;
	status = 0;
	while (i >= 0)
	{
		if (pthread_mutex_unlock(mutexes[i]) != 0)
			status = -1;
		i--;
	}
	if (status == -1)
		return (-1);
	return (0);
}
