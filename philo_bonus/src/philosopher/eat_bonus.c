/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:35:53 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/30 22:39:25 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "sim_bonus.h"
#include "philo_bonus.h"
#include "utils_bonus.h"

static int	devour(t_philo *philo)
{
	const long	start = philo->sim->start;
	const int	id = philo->id;

	if (acquire_locks(philo) != 0)
		return (-1);
	if (sem_wait(philo->sim->printer) != 0)
		exit(1);
	if (philo->sim->state != SIM_RUNNING)
		return (release_locks(philo), -1);
	philo->last_meal = now();
	philo->next_meal = philo->last_meal + philo->sim->time_to_eat * 2 + 10;
	philo->meal_eaten++;
	if (
		printf("%ld %d is eating\n", philo->last_meal - start, id) < 0
		|| sem_post(philo->sim->printer) != 0
		|| pthread_mutex_unlock(philo->meal_mutex) != 0
		|| pthread_mutex_unlock(philo->sim->state_mutex) != 0
	)
		exit(1);
	msleep(philo->sim->time_to_eat, philo->sim);
	return (0);
}

void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0 && philo->next_meal == 0)
		msleep(50, NULL);
	else if (philo->sim->number_of_philos % 2 == 1 && philo->next_meal)
		msleep(philo->next_meal - now(), NULL);
	if (sem_wait(philo->sim->forks) != 0)
		exit(1);
	if (print("has taken a fork", philo) != 0)
		return ;
	if (sem_wait(philo->sim->forks) != 0)
		exit(1);
	if (print("has taken a fork", philo) != 0)
		return ;
	if (devour(philo) != 0)
		return ;
	if (sem_post(philo->sim->forks) != 0 || sem_post(philo->sim->forks) != 0)
		exit(1);
}
