/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:35:53 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/02 20:04:39 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	eat_with_one_fork(t_philo *philo)
{
	lock(philo->left_fork, "eat_with_one_fork: lock: left_fork");
	print(philo->id, "has taken a fork", philo->sim);
	unlock(philo->left_fork, "eat_with_one_fork: unlock: left_fork");
	msleep(philo->sim->time_to_die, philo->sim->time_to_die);
}

void	eat(t_philo *philo)
{
	long	delay;

	if (philo->sim->number_of_forks == 1)
		return (eat_with_one_fork(philo));
	if (philo->id % 2 == 0 && philo->next_meal == 0)
		msleep(10, 10);
	delay = philo->next_meal - now();
	if (philo->sim->number_of_philos % 2 == 1 && delay > 0)
		msleep(delay, delay);
	lock(philo->left_fork, "eat: lock: left_fork mutex");
	print(philo->id, "has taken a fork", philo->sim);
	lock(philo->right_fork, "eat: lock: right_fork mutex");
	print(philo->id, "has taken a fork", philo->sim);
	lock(philo->meal_mutex, "eat: lock: meal_mutex");
	philo->last_meal = now();
	philo->next_meal = philo->last_meal + philo->sim->time_to_eat * 2 + 1;
	philo->meal_count++;
	unlock(philo->meal_mutex, "eat: unlock: meal_mutex");
	print(philo->id, "is eating", philo->sim);
	msleep(philo->sim->time_to_eat, philo->sim->time_to_die);
	unlock(philo->right_fork, "eat: unlock: right_fork mutex");
	unlock(philo->left_fork, "eat: unlock: left_fork mutex");
}
