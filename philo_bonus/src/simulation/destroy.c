/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:31:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/25 23:02:14 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include "sim.h"

static void	wait_all(t_sim *sim)
{
	int		i;
	int		wstatus;
	t_philo	philo;

	i = 0;
	while (i < sim->number_of_pids)
	{
		waitpid(-1, &wstatus, 0);
		if (wstatus != 0)
		{
			i = 0;
			while (i < sim->number_of_pids)
			{
				philo = sim->philos[i++];
				kill(philo.pid, SIGKILL);
			}
			break ;
		}
		i++;
	}
}

static void	delete_philos(t_sim *sim)
{
	int		i;
	t_philo	philo;

	i = 0;
	while (i < sim->number_of_philos)
	{
		philo = sim->philos[i];
		pthread_mutex_destroy(philo.meal_mutex);
		free(philo.meal_mutex);
		i++;
	}
	free(sim->philos);
}

void	destroy(t_sim *sim)
{
	wait_all(sim);
	sem_unlink(FORKS_SEM);
	sem_unlink(PRINTER_SEM);
	sem_close(sim->forks);
	sem_close(sim->printer);
	pthread_mutex_destroy(sim->state_mutex);
	free(sim->state_mutex);
	delete_philos(sim);
}
