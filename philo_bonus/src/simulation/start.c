/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 00:37:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/25 14:29:08 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include "utility.h"

int	start(t_sim *sim)
{
	t_philo	*philo;

	sim->start = now();
	if (sim->start == -1)
		return (-1);
	sim->number_of_pids = 0;
	while (sim->number_of_pids < sim->number_of_philos)
	{
		philo = sim->philos + sim->number_of_pids;
		philo->pid = fork();
		if (philo->pid == -1)
			return (write(2, "launch_processes: fork\n", 23), -1);
		if (philo->pid == 0)
			philo_routine(philo);
		sim->number_of_pids++;
	}
	return (0);
}
