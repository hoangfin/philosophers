/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sim_state.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:41:43 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/06 15:47:43 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "types.h"
#include "utils.h"

static int	update_state(t_philo_state state, t_philo *philo)
{
	long	elapsed_time;

	if (pthread_mutex_lock(philo->state_mutex) != 0)
		return (write(2, "pthread_mutex_lock: state_mutex\n", 32), -1);
	philo->state = state;
	elapsed_time = now() - philo->start;
	if (elapsed_time < 0)
		return (-1);
	if (print_state(elapsed_time, philo->id, state, philo->app) == -1)
		return (pthread_mutex_lock(philo->state_mutex), -1);
	if (pthread_mutex_unlock(philo->state_mutex) != 0)
		return (write(2, "pthread_mutex_unlock: state_mutex\n", 34), -1);
	return (0);
}

static int	handle_eating_state(t_philo_state state, t_philo *philo)
{
	pthread_mutex_t	*mutexes[2];
	long			elapsed_time;

	mutexes[0] = philo->state_mutex;
	mutexes[1] = philo->meal_mutex;
	if (acquire_locks(mutexes, 2, NULL, NULL) == -1)
		return (-1);
	philo->state = EATING;
	philo->last_meal = now();
	if (philo->last_meal == -1)
		return (release_locks(mutexes, 2), -1);
	elapsed_time = philo->last_meal - philo->start;
	philo->meal_eaten++;
	if (print_state(elapsed_time, philo->id, state, philo->app) == -1)
		return (release_locks(mutexes, 2), -1);
	if (release_locks(mutexes, 2) == -1)
		return (-1);
	return (0);
}

int	set_philo_state(t_philo_state state, t_philo *philo)
{
	if (state == EATING)
	{
		if (handle_eating_state(state, philo) == -1)
			return (-1);
	}
	else if (update_state(state, philo) == -1)
		return (-1);
	return (0);
}
