/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:31:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/29 19:20:42 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "simulation.h"

static void	delete_forks(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->number_of_forks)
	{
		pthread_mutex_destroy(sim->forks[i]);
		free(sim->forks[i]);
		i++;
	}
	free(sim->forks);
}

static void	delete_philos(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->number_of_philos)
	{
		pthread_mutex_destroy(sim->philos[i].meal_mutex);
		free(sim->philos[i].meal_mutex);
		free(sim->philos[i].thread);
		i++;
	}
	free(sim->philos);
}

void	destroy(t_sim *sim)
{
	delete_forks(sim);
	delete_philos(sim);
	pthread_mutex_destroy(sim->state_mutex);
	pthread_mutex_destroy(sim->printer_mutex);
	free(sim->state_mutex);
	free(sim->printer_mutex);
	free(sim->monitor_thread);
}
