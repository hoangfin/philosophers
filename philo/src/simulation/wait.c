/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:46:06 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/13 17:39:25 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <errno.h>
#include "simulation.h"

int	wait(t_sim *sim)
{
	int			i;
	int			rc;
	pthread_t	thread;

	i = 0;
	pthread_join(*sim->monitor_thread, NULL);
	while (i < sim->number_of_threads)
	{
		thread = *(sim->philos[i].thread);
		rc = pthread_join(thread, NULL);
		if (rc != 0 && rc != ESRCH && rc != EINVAL)
			return (-1);
		i++;
	}
	return (0);
}
