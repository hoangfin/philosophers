/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:35:53 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/13 19:07:52 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosopher.h"
#include "printer.h"
#include "utils.h"

static int	get_forks(t_philo *philo)
{
	if (pthread_mutex_lock(philo->left_fork) != 0)
		return (print_error("Error: lock left_fork", philo->sim), -1);
	if (set_philo_state(PHILO_TAKE_A_FORK, philo) == -1)
	{
		print_error("Error: set_philo_state: take left_fork", philo->sim);
		pthread_mutex_unlock(philo->left_fork);
		return (-1);
	}
	if (pthread_mutex_lock(philo->right_fork) != 0)
	{
		print_error("Error: lock right_fork", philo->sim);
		pthread_mutex_unlock(philo->left_fork);
		return (-1);
	}
	if (set_philo_state(PHILO_TAKE_A_FORK, philo) == -1)
	{
		print_error("Error: set_philo_state: take right_fork", philo->sim);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (-1);
	}
	return (0);
}

static int	release_forks(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->right_fork) != 0)
	{
		print_error("Error: pthread_mutex_unlock: right_fork", philo->sim);
		return (-1);
	}
	if (pthread_mutex_unlock(philo->left_fork) != 0)
	{
		print_error("Error: pthread_mutex_unlock: left_fork", philo->sim);
		return (-1);
	}
	return (0);
}

int	eat(t_philo *philo)
{
	if (get_forks(philo) == -1)
		return (-1);
	if (set_philo_state(PHILO_EATING, philo) == -1)
	{
		print_error("Error: set_philo_state: PHILO_EATING", philo->sim);
		release_forks(philo);
		return (-1);
	}
	if (msleep(philo->sim->time_to_eat) == -1)
	{
		print_error("Error: msleep", philo->sim);
		release_forks(philo);
		return (-1);
	}
	if (release_forks(philo) == -1)
		return (-1);
	return (0);
}
