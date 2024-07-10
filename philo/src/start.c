/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 00:37:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/08 19:21:40 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

int	start(t_app *app)
{
	pthread_t	monitor_thread;
	pthread_t	*thread;
	t_philo		*philo;

	app->sim_state = SIM_RUNNING;
	while (app->number_of_threads < app->number_of_philos)
	{
		thread = app->philos[app->number_of_threads].thread;
		philo = app->philos + app->number_of_threads;
		// philo->start = now();
		// philo->last_meal = now();
		if (pthread_create(thread, NULL, philo_routine, philo) != 0)
			return (set_sim_state(SIM_ERROR, app), -1);
		app->number_of_threads++;
	}
	if (
		pthread_create(&monitor_thread, NULL, monitor_routine, app) != 0
		|| pthread_detach(monitor_thread) != 0
	)
		return (set_sim_state(SIM_ERROR, app), -1);
	return (0);
}
