/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:35:53 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/01 01:56:06 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include "philosopher.h"
#include "utils.h"

static int	get_forks(t_philo *philo)
{
	if (philo->sim->number_of_philos % 2 == 1 && philo->next_meal != 0)
		msleep(philo->next_meal - now(), NULL);
	lock(philo->left_fork, "eat: lock: left_fork mutex");
	if (print_philo_state("has taken a fork", philo) != 0)
	{
		unlock(philo->left_fork, "eat: unlock: left_fork mutex");
		return (-1);
	}
	lock(philo->right_fork, "eat: lock: right_fork mutex");
	if (print_philo_state("has taken a fork", philo) != 0)
	{
		unlock(philo->right_fork, "eat: unlock: right_fork mutex");
		unlock(philo->left_fork, "eat: unlock: left_fork mutex");
		return (-1);
	}
	return (0);
}

void	eat(t_philo *philo)
{
	int	status;

	if (get_forks(philo) != 0)
		return ;
	lock(philo->meal_mutex, "eat: lock: meal_mutex");
	philo->last_meal = now();
	philo->next_meal = philo->last_meal + philo->sim->time_to_eat * 2 + 1;
	philo->meal_count++;
	status = print_philo_state("is eating", philo);
	unlock(philo->meal_mutex, "eat: unlock: meal_mutex");
	if (status == 0)
		msleep(philo->sim->time_to_eat, philo->sim);
	unlock(philo->right_fork, "eat: unlock: right_fork mutex");
	unlock(philo->left_fork, "eat: unlock: left_fork mutex");
}
