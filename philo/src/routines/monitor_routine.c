/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:16:48 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/09 23:55:00 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "philo.h"
#include "utils.h"

static t_bool	is_dead(t_philo *philo, t_app *app)
{
	long	current_time;

	if (pthread_mutex_lock(philo->state_mutex) != 0)
		return (write(2, "pthread_mutex_lock: state_mutex\n", 32), true);
	if (philo->state == EATING || philo->state == SLEEPING)
		return (pthread_mutex_unlock(philo->state_mutex), false);
	if (pthread_mutex_unlock(philo->state_mutex) != 0)
		return (write(2, "pthread_mutex_unlock: state_mutex\n", 34), true);
	if (pthread_mutex_lock(philo->meal_mutex) != 0)
		return (write(2, "pthread_mutex_lock: meal_mutex\n", 31), true);
	current_time = now();
	if (current_time < 0)
		return (pthread_mutex_unlock(philo->meal_mutex), true);
	if (current_time - philo->last_meal >= app->time_to_die)
	{
		print_state(current_time - philo->start, philo->id, DIED, app);
		pthread_mutex_unlock(philo->meal_mutex);
		return (true);
	}
	if (pthread_mutex_unlock(philo->meal_mutex) != 0)
		return (write(2, "pthread_mutex_unlock: meal_mutex\n", 33), true);
	return (false);
}

static t_bool	has_a_dead_philo(t_app *app)
{
	int	i;

	i = 0;
	while (i < app->number_of_philos)
	{
		if (is_dead(app->philos + i, app))
			return (true);
		i++;
	}
	return (false);
}

static t_bool	has_enough_meal_eaten(t_app *app)
{
	int		i;
	t_philo	philo;

	if (app->meal_limit == -1)
		return (false);
	i = 0;
	while (i < app->number_of_philos)
	{
		philo = app->philos[i];
		if (pthread_mutex_lock(philo.meal_mutex) != 0)
			return (
				write(2, "pthread_mutex_lock: meal_mutex\n", 31),
				true
			);
		if (philo.meal_eaten < app->meal_limit)
			return (pthread_mutex_unlock(philo.meal_mutex), false);
		if (pthread_mutex_unlock(philo.meal_mutex) != 0)
			return (
				write(2, "pthread_mutex_unlock: meal_mutex\n", 33),
				true
			);
		i++;
	}
	return (true);
}

void	*monitor_routine(void *arg)
{
	t_app *const	app = (t_app *)arg;

	while (1)
	{
		if (has_a_dead_philo(app) || has_enough_meal_eaten(app))
			return (set_sim_state(SIM_END, app), NULL);
	}
	return (NULL);
}
