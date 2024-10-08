/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:35:53 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/14 17:05:42 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sim.h"
#include "utils.h"

static void	eat_with_one_fork(t_philo *philo)
{
	lock(philo->left_fork, "eat_with_one_fork: lock: left_fork");
	print(philo->id, "has taken a fork", philo->sim);
	unlock(philo->left_fork, "eat_with_one_fork: unlock: left_fork");
	msleep(philo->sim->time_to_die + 1, philo->sim);
}

void	eat(t_philo *philo)
{
	long	delay;

	if (philo->sim->number_of_forks == 1)
		return (eat_with_one_fork(philo));
	if (philo->id % 2 == 0 && philo->next_meal == 0)
		msleep(philo->sim->time_to_eat / 2, philo->sim);
	delay = philo->next_meal - now();
	if (philo->sim->number_of_philos % 2 == 1 && delay > 0)
		msleep(delay, philo->sim);
	lock(philo->left_fork, "eat: lock: left_fork mutex");
	print(philo->id, "has taken a fork", philo->sim);
	lock(philo->right_fork, "eat: lock: right_fork mutex");
	print(philo->id, "has taken a fork", philo->sim);
	lock(philo->meal_mutex, "eat: lock: meal_mutex");
	philo->last_meal = now();
	philo->next_meal = philo->last_meal + philo->sim->time_to_eat * 2 + 1;
	philo->meal_count++;
	print(philo->id, "is eating", philo->sim);
	unlock(philo->meal_mutex, "eat: unlock: meal_mutex");
	msleep(philo->sim->time_to_eat, philo->sim);
	unlock(philo->right_fork, "eat: unlock: right_fork mutex");
	unlock(philo->left_fork, "eat: unlock: left_fork mutex");
}
