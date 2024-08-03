/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:31:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/02 14:19:06 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "sim.h"

static int	join_all_threads(t_sim *sim)
{
	int			i;
	int			status;
	pthread_t	thread;

	status = 0;
	if (sim->monitor_thread != NULL)
	{
		if (pthread_join(*sim->monitor_thread, NULL) != 0)
			status = -1;
	}
	i = 0;
	while (i < sim->number_of_threads)
	{
		thread = *(sim->philos[i].thread);
		if (pthread_join(thread, NULL) != 0)
			status = -1;
		i++;
	}
	return (status);
}

static int	delete_forks(t_sim *sim)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < sim->number_of_forks)
	{
		if (pthread_mutex_destroy(sim->forks[i]) != 0)
			status = -1;
		free(sim->forks[i]);
		i++;
	}
	free(sim->forks);
	return (status);
}

static int	delete_philos(t_sim *sim)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < sim->number_of_philos)
	{
		if (pthread_mutex_destroy(sim->philos[i].meal_mutex) != 0)
			status = -1;
		free(sim->philos[i].meal_mutex);
		free(sim->philos[i].thread);
		i++;
	}
	free(sim->philos);
	return (status);
}

int	destroy(t_sim *sim)
{
	int	statuses[5];

	statuses[0] = join_all_threads(sim);
	statuses[1] = delete_forks(sim);
	statuses[2] = delete_philos(sim);
	statuses[3] = pthread_mutex_destroy(sim->state_mutex);
	statuses[4] = pthread_mutex_destroy(sim->printer_mutex);
	free(sim->state_mutex);
	free(sim->printer_mutex);
	free(sim->monitor_thread);
	if (
		statuses[0] != 0
		|| statuses[1] != 0
		|| statuses[2] != 0
		|| statuses[3] != 0
		|| statuses[4] != 0
	)
		return (-1);
	return (0);
}
