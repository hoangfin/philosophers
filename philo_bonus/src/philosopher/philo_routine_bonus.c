/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 01:47:58 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/03 18:53:24 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo_bonus.h"
#include "utils_bonus.h"

static void	philo_exit(int exit_status, t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->number_of_philos)
	{
		pthread_mutex_destroy(sim->philos[i].meal_mutex);
		free(sim->philos[i].meal_mutex);
		i++;
	}
	free(sim->philos);
	pthread_mutex_destroy(sim->state_mutex);
	free(sim->state_mutex);
	exit(exit_status);
}

void	philo_routine(t_philo *philo)
{
	const long	delay = philo->sim->start - now();
	pthread_t	monitor_thread;
	t_sim_state	sim_state;

	if (pthread_create(&monitor_thread, NULL, monitor_routine, philo) != 0)
		philo_exit(1, philo->sim);
	if (delay > 0)
		msleep(delay, delay);
	while (1)
	{
		lock(philo->sim->state_mutex, "philo_routine: lock: state_mutex");
		sim_state = philo->sim->state;
		unlock(philo->sim->state_mutex, "philo_routine: unlock: state_mutex");
		if (sim_state != SIM_RUNNING)
			break ;
		think(philo);
		eat(philo);
		ft_sleep(philo);
	}
	if (pthread_join(monitor_thread, NULL) != 0)
		philo_exit(1, philo->sim);
	if (sim_state == SIM_END_BY_PHILO_DEATH)
		philo_exit(DEATH_EXIT_CODE, philo->sim);
	philo_exit(0, philo->sim);
}
