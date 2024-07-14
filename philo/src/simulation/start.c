/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 00:37:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/13 19:32:33 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "simulation.h"
#include "routine.h"
#include "utils.h"

static int	set_start(t_sim *sim)
{
	int	i;

	sim->state = SIM_RUNNING;
	sim->start = now();
	if (sim->start == -1)
	{
		write(2, "Error: Couldn't get current time\n", 33);
		return (-1);
	}
	i = 0;
	while (i < sim->number_of_philos)
	{
		sim->philos[i].last_meal = sim->start;
		i++;
	}
	return (0);
}

int	start(t_sim *sim)
{
	pthread_t	*thread;
	t_philo		*philo;

	if (set_start(sim) == -1)
		return (-1);
	if (pthread_create(sim->monitor_thread, NULL, monitor_routine, sim) != 0)
		return (write(2, "Error: Failed to create monitor thread\n", 39), -1);
	sim->number_of_threads = 0;
	while (sim->number_of_threads < sim->number_of_philos)
	{
		thread = sim->philos[sim->number_of_threads].thread;
		philo = sim->philos + sim->number_of_threads;
		if (pthread_create(thread, NULL, philosopher_routine, philo) != 0)
			return (set_sim_state(SIM_ERROR, sim), -1);
		sim->number_of_threads++;
	}
	return (0);
}
