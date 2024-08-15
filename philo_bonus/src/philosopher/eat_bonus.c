/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:35:53 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/15 22:14:45 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "utils_bonus.h"

static void	eat_with_one_fork(t_philo *philo)
{
	lock_sem(philo->sim->forks, "eat_with_one_fork: lock_sem: forks");
	print("has taken a fork", philo);
	unlock_sem(philo->sim->forks, "eat_with_one_fork: unlock_sem: forks");
	msleep(philo->sim->time_to_die + 1, philo);
}

void	eat(t_philo *philo)
{
	long	delay;

	if (philo->sim->number_of_philos == 1)
		return (eat_with_one_fork(philo));
	if (philo->id % 2 == 0 && philo->next_meal == 0)
		msleep(philo->sim->time_to_eat / 2, philo);
	delay = philo->next_meal - now();
	if (philo->sim->number_of_philos % 2 == 1 && delay > 0)
		msleep(delay, NULL);
	lock_sem(philo->sim->forks, "eat: lock_sem: forks");
	print("has taken a fork", philo);
	lock_sem(philo->sim->forks, "eat: lock_sem: forks");
	print("has taken a fork", philo);
	lock_sem(philo->meal_sem, "eat: lock_sem: meal_sem");
	philo->last_meal = now();
	philo->next_meal = philo->last_meal + philo->sim->time_to_eat * 2 + 1;
	philo->meal_count++;
	print("is eating", philo);
	unlock_sem(philo->meal_sem, "eat: unlock_sem: meal_sem");
	msleep(philo->sim->time_to_eat, philo);
	unlock_sem(philo->sim->forks, "eat: unlock_sem: forks");
	unlock_sem(philo->sim->forks, "eat: unlock_sem: forks");
}
