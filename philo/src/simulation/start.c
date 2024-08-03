/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 00:37:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/02 19:45:50 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "sim.h"
#include "routine.h"
#include "utils.h"

static int	launch_monitor_thread(t_sim *sim)
{
	int		i;
	t_philo	*philo;

	sim->start = now() + TOTAL_THREAD_CREATION_TIME_MS;
	i = 0;
	while (i < sim->number_of_philos)
	{
		philo = sim->philos + i;
		philo->last_meal = sim->start;
		i++;
	}
	sim->state = SIM_RUNNING;
	if (pthread_create(sim->monitor_thread, NULL, monitor_routine, sim) != 0)
	{
		write(STDERR_FILENO, "launch_monitor_thread: ", 23);
		write(STDERR_FILENO, "pthread_create: sim->monitor_thread\n", 36);
		return (-1);
	}
	return (0);
}

int	start(t_sim *sim)
{
	pthread_t	*thread;
	t_philo		*philo;

	if (launch_monitor_thread(sim) != 0)
		return (-1);
	sim->number_of_threads = 0;
	while (sim->number_of_threads < sim->number_of_philos)
	{
		thread = sim->philos[sim->number_of_threads].thread;
		philo = sim->philos + sim->number_of_threads;
		if (pthread_create(thread, NULL, philo_routine, philo) != 0)
		{
			lock(sim->state_mutex, "start: lock: state_mutex");
			sim->state = SIM_ERROR;
			unlock(sim->state_mutex, "start: unlock: state_mutex");
			return (-1);
		}
		sim->number_of_threads++;
	}
	return (0);
}
