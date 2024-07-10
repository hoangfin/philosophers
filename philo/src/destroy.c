/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:31:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/08 17:45:40 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

static void	delete_forks(t_app *app)
{
	int	i;

	i = 0;
	while (i < app->number_of_forks)
	{
		pthread_mutex_destroy(app->forks[i]);
		free(app->forks[i]);
		i++;
	}
	free(app->forks);
}

static void	delete_philos(t_app *app)
{
	int	i;

	i = 0;
	while (i < app->number_of_philos)
	{
		pthread_mutex_destroy(app->philos[i].state_mutex);
		pthread_mutex_destroy(app->philos[i].meal_mutex);
		free(app->philos[i].state_mutex);
		free(app->philos[i].meal_mutex);
		free(app->philos[i].thread);
		i++;
	}
	free(app->philos);
}

void	destroy(t_app *app)
{
	delete_forks(app);
	delete_philos(app);
	pthread_mutex_destroy(app->sim_state_mutex);
	free(app->sim_state_mutex);
}
