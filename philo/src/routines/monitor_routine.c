/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:16:48 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/30 00:44:53 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "simulation.h"
#include "philosopher.h"
#include "utils.h"

static t_bool	has_a_dead_philo(t_sim *sim)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < sim->number_of_philos)
	{
		philo = sim->philos + i;
		lock(philo->meal_mutex, "has_a_dead_philo: lock");
		if (now() - philo->last_meal >= sim->time_to_die)
		{
			lock(philo->sim->state_mutex, "has_a_dead_philo: lock");
			philo->sim->state = SIM_END;
			unlock(philo->sim->state_mutex, "has_a_dead_philo: unlock");
			unlock(philo->meal_mutex, "has_a_dead_philo: unlock");
			lock(philo->sim->printer_mutex, "has_a_dead_philo: lock");
			printf("%ld %d died\n", now() - philo->sim->start, philo->id);
			unlock(philo->sim->printer_mutex, "has_a_dead_philo: unlock");
			return (true);
		}
		unlock(philo->meal_mutex, "has_a_dead_philo: unlock");
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
		lock(philo->meal_mutex, "hit_meal_limit: lock");
		if (philo->meal_count < sim->meal_limit)
		{
			unlock(philo->meal_mutex, "hit_meal_limit: unlock");
			return (false);
		}
		unlock(philo->meal_mutex, "hit_meal_limit: unlock");
		i++;
	}
	lock(sim->state_mutex, "hit_meal_limit: lock");
	sim->state = SIM_END;
	unlock(sim->state_mutex, "hit_meal_limit: unlock");
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
		if (usleep(100) != 0)
		{
			write(STDERR_FILENO, "monitor_routine: usleep\n", 24);
			exit(1);
		}
	}
	return (NULL);
}
