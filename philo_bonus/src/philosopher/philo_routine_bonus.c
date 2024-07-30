/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 01:47:58 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/30 22:43:00 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "sim_bonus.h"
#include "philo_bonus.h"
#include "utils_bonus.h"

static void	philo_exit(int exit_status, t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->number_of_philos)
	{
		pthread_mutex_destroy(sim->philos[i].meal_mutex);
		free(sim->philos[i].meal_mutex);
		i++;
	}
	free(sim->philos);
	pthread_mutex_destroy(sim->state_mutex);
	free(sim->state_mutex);
	sem_unlink(FORKS_SEM);
	sem_unlink(PRINTER_SEM);
	sem_close(sim->forks);
	sem_close(sim->printer);
	exit(exit_status);
}

static void	*monitor_routine(void *arg)
{
	t_philo *const	philo = (t_philo *)arg;
	t_sim *const	sim = philo->sim;

	while (1)
	{
		if (acquire_locks(philo) != 0)
			break ;
		if (sim->meal_limit != -1 && philo->meal_eaten >= sim->meal_limit)
		{
			philo->sim->state = SIM_END;
			release_locks(philo);
			break ;
		}
		if (
			pthread_mutex_unlock(philo->meal_mutex) != 0
			|| pthread_mutex_unlock(philo->sim->state_mutex) != 0
		)
			exit(1);
		usleep(1000);
	}
	return (NULL);
}

void	philo_routine(t_philo *philo)
{
	const long	elapsed_time = now() - philo->sim->start;
	pthread_t	monitor_thread;
	t_sim_state	sim_state;

	philo->sim->start = philo->sim->start + SIM_START_TIME;
	philo->last_meal = philo->sim->start;
	msleep(SIM_START_TIME - elapsed_time, NULL);
	if (pthread_create(&monitor_thread, NULL, monitor_routine, philo) != 0)
		philo_exit(1, philo->sim);
	while (1)
	{
		sim_state = get_sim_state(philo->sim);
		if (sim_state == SIM_END || sim_state == SIM_ERROR)
			break ;
		think(philo);
		eat(philo);
		ft_sleep(philo);
	}
	if (pthread_join(monitor_thread, NULL) != 0 || sim_state == SIM_ERROR)
		philo_exit(1, philo->sim);
	philo_exit(0, philo->sim);
}
