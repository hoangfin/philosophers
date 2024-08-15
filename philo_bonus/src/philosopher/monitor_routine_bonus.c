/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 01:47:58 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/15 20:47:00 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "philo_bonus.h"
#include "utils_bonus.h"

static int	is_philo_dead(t_philo *philo)
{
	t_sim *const	sim = philo->sim;

	lock_sem(philo->meal_sem, "is_philo_dead: lock meal_sem");
	if (now() - philo->last_meal >= sim->time_to_die)
	{
		lock_sem(philo->state_sem, "is_philo_dead: lock state_sem");
		philo->is_dead = 1;
		unlock_sem(philo->state_sem, "is_philo_dead: unlock state_sem");
		unlock_sem(philo->meal_sem, "is_philo_dead: unlock meal_sem");
		lock_sem(sim->printer_sem, "is_philo_dead: lock_sem: printer_sem");
		if (printf("%ld %d died\n", now() - sim->start, philo->id) < 0)
		{
			write(STDERR_FILENO, "is_philo_dead: printf\n", 22);
			exit(1);
		}
		return (1);
	}
	unlock_sem(philo->meal_sem, "is_philo_dead: unlock meal_sem");
	return (0);
}

static int	hit_meal_limit(t_philo *philo)
{
	if (philo->sim->meal_limit == -1)
		return (0);
	lock_sem(philo->meal_sem, "hit_meal_limit: lock meal_sem");
	if (philo->meal_count < philo->sim->meal_limit)
	{
		unlock_sem(philo->meal_sem, "hit_meal_limit: unlock meal_sem");
		return (0);
	}
	lock_sem(philo->state_sem, "hit_meal_limit: lock state_sem");
	philo->has_enough_meal = 1;
	unlock_sem(philo->state_sem, "hit_meal_limit: unlock state_sem");
	unlock_sem(philo->meal_sem, "hit_meal_limit: unlock meal_sem");
	return (1);
}

void	*monitor_routine(void *arg)
{
	t_philo *const	philo = (t_philo *)arg;
	const long		delay = philo->sim->start - now();

	if (delay > 0)
		msleep(delay, NULL);
	while (1)
	{
		if (is_philo_dead(philo) || hit_meal_limit(philo) )
			break ;
		if (usleep(1000) != 0)
		{
			write(STDERR_FILENO, "monitor_routine: usleep\n", 24);
			exit(1);
		}
	}
	return (NULL);
}
