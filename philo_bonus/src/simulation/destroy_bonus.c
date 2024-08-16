/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:31:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/16 17:08:39 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include "sim_bonus.h"
#include "utils_bonus.h"

static int	wait_all(t_sim *sim)
{
	int		i;
	int		wstatus;
	int		status;
	t_philo	philo;

	i = 0;
	status = 0;
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
			if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) != DEATH_EXIT_CODE)
				status = -1;
			break ;
		}
		i++;
	}
	return (status);
}

static int	delete_philos(t_sim *sim)
{
	int		i;
	int		status;
	t_philo	philo;

	i = 0;
	status = 0;
	while (i < sim->number_of_philos)
	{
		philo = sim->philos[i];
		if (sem_close(philo.meal_sem) != 0)
			status = -1;
		if (sem_close(philo.state_sem) != 0)
			status = -1;
		set_name(sim->sem_name_buf, "/state_sem_", philo.id);
		if (sem_unlink(sim->sem_name_buf) != 0)
			status = -1;
		set_name(sim->sem_name_buf, "/meal_sem_", philo.id);
		if (sem_unlink(sim->sem_name_buf) != 0)
			status = -1;
		i++;
	}
	free(sim->philos);
	return (status);
}

int	destroy(t_sim *sim)
{
	int	statuses[6];

	statuses[0] = wait_all(sim);
	statuses[1] = delete_philos(sim);
	statuses[2] = sem_close(sim->forks);
	statuses[3] = sem_close(sim->printer_sem);
	statuses[4] = sem_unlink(FORKS_SEM);
	statuses[5] = sem_unlink(PRINTER_SEM);
	if (
		statuses[0] != 0
		|| statuses[1] != 0
		|| statuses[2] != 0
		|| statuses[3] != 0
		|| statuses[4] != 0
		|| statuses[5] != 0
	)
		return (-1);
	return (0);
}
