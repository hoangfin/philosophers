/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acquire_locks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:55:44 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/27 21:23:33 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "philo.h"
#include "utility.h"

static int	is_dead(t_philo *philo)
{
	long	current_time;

	current_time = now();
	if (current_time - philo->last_meal >= philo->sim->time_to_die)
	{
		philo->sim->state = SIM_ERROR;
		if (
			pthread_mutex_unlock(philo->meal_mutex) != 0
			|| pthread_mutex_unlock(philo->sim->state_mutex) != 0
			|| sem_wait(philo->sim->printer) != 0
		)
			exit(1);
		current_time = now();
		printf("%ld %d died\n", current_time - philo->sim->start, philo->id);
		return (1);
	}
	return (0);
}

int	acquire_locks(t_philo *philo)
{
	if (pthread_mutex_lock(philo->sim->state_mutex) != 0)
		exit(1);
	if (philo->sim->state != SIM_RUNNING)
		return (pthread_mutex_unlock(philo->sim->state_mutex), -1);
	if (pthread_mutex_lock(philo->meal_mutex) != 0)
		exit(1);
	if (philo->sim->state != SIM_RUNNING)
	{
		pthread_mutex_unlock(philo->meal_mutex);
		pthread_mutex_unlock(philo->sim->state_mutex);
		return (-1);
	}
	if (is_dead(philo))
		return (-1);
	return (0);
}
