/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 01:47:58 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/16 17:13:47 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "philo_bonus.h"
#include "utils_bonus.h"

static void	philo_exit(int exit_status, t_philo *philo)
{
	int		i;
	int		status;
	t_philo	ph;

	i = 0;
	status = 0;
	while (i < philo->sim->number_of_philos)
	{
		ph = philo->sim->philos[i];
		if (sem_close(ph.meal_sem) != 0)
			status = -1;
		if (sem_close(ph.state_sem) != 0)
			status = -1;
		i++;
	}
	if (sem_close(philo->sim->forks) != 0)
		status = -1;
	if (sem_close(philo->sim->printer_sem) != 0)
		status = -1;
	free(philo->sim->philos);
	if (status == 0)
		exit(exit_status);
	exit(1);
}

static int	should_terminate(t_philo *philo)
{
	int	should_end;

	should_end = 0;
	lock_sem(philo->state_sem, "should_terminate: lock state_sem");
	if (philo->is_dead || philo->has_enough_meal)
		should_end = 1;
	unlock_sem(philo->state_sem, "should_terminate: unlock state_sem");
	if (should_end)
		return (1);
	return (0);
}

void	philo_routine(t_philo *philo)
{
	const long	delay = philo->sim->start - now();
	pthread_t	monitor_thread;

	if (pthread_create(&monitor_thread, NULL, monitor_routine, philo) != 0)
		philo_exit(1, philo);
	if (delay > 0)
		msleep(delay, NULL);
	while (1)
	{
		if (should_terminate(philo))
			break ;
		think(philo);
		eat(philo);
		ft_sleep(philo);
	}
	if (pthread_join(monitor_thread, NULL) != 0)
		philo_exit(1, philo);
	if (philo->is_dead)
		philo_exit(DEATH_EXIT_CODE, philo);
	philo_exit(0, philo);
}
