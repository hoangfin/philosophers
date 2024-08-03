/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 01:47:58 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/03 18:51:21 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils_bonus.h"

static int	is_philo_dead(long last_meal, t_philo *philo)
{
	t_sim *const	sim = philo->sim;

	if (now() - last_meal >= sim->time_to_die)
	{
		lock(sim->state_mutex, "is_philo_dead: lock: state_mutex");
		sim->state = SIM_END_BY_PHILO_DEATH;
		unlock(sim->state_mutex, "is_philo_dead: unlock: state_mutex");
		lock_sem(sim->printer_sem, "is_philo_dead: lock_sem: printer_sem");
		if (printf("%ld %d died\n", now() - sim->start, philo->id) < 0)
		{
			write(STDERR_FILENO, "is_philo_dead: printf\n", 22);
			exit(1);
		}
		return (1);
	}
	return (0);
}

static int	hit_meal_limit(int meal_count, t_sim *sim)
{
	if (sim->meal_limit == -1)
		return (0);
	if (meal_count < sim->meal_limit)
		return (0);
	lock(sim->state_mutex, "hit_meal_limit: lock: state_mutex");
	sim->state = SIM_END;
	unlock(sim->state_mutex, "hit_meal_limit: unlock: state_mutex");
	return (1);
}

void	*monitor_routine(void *arg)
{
	t_philo *const	philo = (t_philo *)arg;
	const long		delay = philo->sim->start - now();
	long			last_meal;
	int				meal_count;

	if (delay > 0)
		msleep(delay, delay);
	while (1)
	{
		lock(philo->meal_mutex, "monitor_routine: lock: meal_mutex");
		last_meal = philo->last_meal;
		meal_count = philo->meal_count;
		unlock(philo->meal_mutex, "monitor_routine: unlock: meal_mutex");
		if (
			is_philo_dead(last_meal, philo)
			|| hit_meal_limit(meal_count, philo->sim)
		)
			break ;
		if (usleep(1000) != 0)
		{
			write(STDERR_FILENO, "monitor_routine: usleep\n", 24);
			exit(1);
		}
	}
	return (NULL);
}
