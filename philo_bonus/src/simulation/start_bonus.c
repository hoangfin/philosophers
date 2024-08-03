/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 00:37:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/03 19:41:38 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo_bonus.h"
#include "utils_bonus.h"

/**
 * The growth of process creation time likely has quadratic polynomial form:
 * ax2 + bx + c
 */
int	start(t_sim *sim)
{
	const int	n = sim->number_of_philos;
	const int	growth_ms = 0.004 * n * n + 0.3 * n + 50;
	t_philo		*philo;

	sim->start = now() + CREATION_TIME_PER_PROCESS_MS * growth_ms;
	sim->number_of_pids = 0;
	while (sim->number_of_pids < sim->number_of_philos)
	{
		philo = sim->philos + sim->number_of_pids;
		philo->last_meal = sim->start;
		philo->pid = fork();
		if (philo->pid == -1)
			return (write(STDERR_FILENO, "start: fork\n", 12), -1);
		if (philo->pid == 0)
			philo_routine(philo);
		sim->number_of_pids++;
	}
	return (0);
}
