/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:16:48 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/14 13:45:43 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "simulation.h"
#include "philosopher.h"
#include "printer.h"
#include "utils.h"

static t_bool	is_dead(t_philo *philo, t_sim *sim)
{
	long	current_time;

	if (pthread_mutex_lock(philo->meal_mutex) != 0)
		return (print_error("Error: lock meal_mutex", sim), true);
	current_time = now();
	if (current_time == -1)
	{
		print_error("Error: Couldn't get current time", sim);
		pthread_mutex_unlock(philo->meal_mutex);
		return (true);
	}
	if (current_time - philo->last_meal >= sim->time_to_die)
	{
		if (set_philo_state(PHILO_DIED, philo) == -1)
			print_error("Error: set_philo_state: PHILO_DIED", sim);
		pthread_mutex_unlock(philo->meal_mutex);
		return (true);
	}
	if (pthread_mutex_unlock(philo->meal_mutex) != 0)
		return (print_error("Error: unlock meal_mutex", sim), true);
	return (false);
}

static t_bool	has_a_dead_philo(t_sim *sim)
{
	int				i;
	t_philo			*philo;
	t_philo_state	state;

	i = 0;
	while (i < sim->number_of_philos)
	{
		philo = sim->philos + i;
		state = get_philo_state(philo);
		if (state == PHILO_UNDEFINED)
			return (print_error("Error: undefined philo state", sim), true);
		if (state == PHILO_EATING || state == PHILO_SLEEPING)
			return (false);
		if (is_dead(philo, sim))
			return (true);
		i++;
	}
	return (false);
}

static t_bool	hit_meal_limit(t_sim *sim)
{
	int		i;
	t_philo	*philo;

	if (sim->meal_limit == -1)
		return (false);
	i = 0;
	while (i < sim->number_of_philos)
	{
		philo = sim->philos + i;
		if (pthread_mutex_lock(philo->meal_mutex) != 0)
			return (print_error("Error: lock meal_mutex", sim), true);
		if (philo->meal_eaten < sim->meal_limit)
			return (pthread_mutex_unlock(philo->meal_mutex), false);
		if (pthread_mutex_unlock(philo->meal_mutex) != 0)
			return (print_error("Error: unlock meal_mutex", sim), true);
		i++;
	}
	set_sim_state(SIM_END, sim);
	return (true);
}

void	*monitor_routine(void *arg)
{
	t_sim	*sim;

	sim = (t_sim *)arg;
	while (1)
	{
		if (has_a_dead_philo(sim) || hit_meal_limit(sim))
			break ;
	}
	return (NULL);
}
