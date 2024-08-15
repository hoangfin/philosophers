/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 01:47:58 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/15 20:47:38 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "philo_bonus.h"
#include "utils_bonus.h"

static void	philo_exit(int exit_status, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->sim->number_of_philos)
	{
		set_name(philo->sim->sem_name_buf, "/state_sem_", philo->id);
		sem_unlink(philo->sim->sem_name_buf);
		set_name(philo->sim->sem_name_buf, "/meal_sem_", philo->id);
		sem_unlink(philo->sim->sem_name_buf);
		sem_close(philo->meal_sem);
		sem_close(philo->state_sem);
		i++;
	}
	sem_unlink(FORKS_SEM);
	sem_unlink(PRINTER_SEM);
	sem_close(philo->sim->forks);
	sem_close(philo->sim->printer_sem);
	free(philo->sim->philos);
	exit(exit_status);
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
