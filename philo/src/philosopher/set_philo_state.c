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
#include "philosopher.h"
#include "utils.h"

static int	print_state(t_philo_state state, long time, int id, t_sim *sim)
{
	pthread_mutex_t	*mutexes[2];

	mutexes[0] = sim->print_mutex;
	mutexes[1] = sim->state_mutex;
	if (acquire_locks(mutexes, 2) == -1)
		return (-1);
	if (sim->state == SIM_RUNNING)
	{
		if (state == PHILO_THINKING)
			printf("%ld %d is thinking\n", time, id);
		else if (state == PHILO_TAKE_A_FORK)
			printf("%ld %d has taken a fork\n", time, id);
		else if (state == PHILO_EATING)
			printf("%ld %d is eating\n", time, id);
		else if (state == PHILO_SLEEPING)
			printf("%ld %d is sleeping\n", time, id);
		else if (state == PHILO_DIED)
		{
			sim->state = SIM_END;
			printf("%ld %d died\n", time, id);
		}
	}
	return (release_locks(mutexes, 2));
}

static int	update_state(t_philo_state state, t_philo *philo)
{
	long	elapsed_time;

	if (pthread_mutex_lock(philo->state_mutex) != 0)
		return (-1);
	philo->state = state;
	elapsed_time = now() - philo->sim->start;
	if (elapsed_time < 0)
		return (-1);
	if (pthread_mutex_unlock(philo->state_mutex) != 0)
		return (-1);
	return (print_state(state, elapsed_time, philo->id, philo->sim));
}

static int	update_eating_state(t_philo_state state, t_philo *philo)
{
	pthread_mutex_t	*mutexes[2];
	long			elapsed_time;

	mutexes[0] = philo->meal_mutex;
	mutexes[1] = philo->state_mutex;
	if (acquire_locks(mutexes, 2) == -1)
		return (-1);
	philo->state = state;
	philo->last_meal = now();
	if (philo->last_meal == -1)
		return (release_locks(mutexes, 2), -1);
	philo->meal_eaten++;
	elapsed_time = philo->last_meal - philo->sim->start;
	if (release_locks(mutexes, 2) == -1)
		return (-1);
	return (print_state(state, elapsed_time, philo->id, philo->sim));
}

int	set_philo_state(t_philo_state state, t_philo *philo)
{
	if (state == PHILO_EATING)
	{
		if (update_eating_state(state, philo) == -1)
			return (-1);
	}
	else if (update_state(state, philo) == -1)
		return (-1);
	return (0);
}
