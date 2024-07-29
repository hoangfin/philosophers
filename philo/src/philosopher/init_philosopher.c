/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:03:44 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/29 19:20:16 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philosopher.h"

int	init_philosopher(t_philo *philo, int id, t_sim *sim)
{
	philo->sim = sim;
	philo->id = id;
	philo->thread = (pthread_t *)malloc(sizeof(pthread_t));
	if (philo->thread == NULL)
		return (-1);
	philo->left_fork = sim->forks[id - 1];
	philo->right_fork = sim->forks[id % sim->number_of_forks];
	philo->meal_mutex = malloc(sizeof(pthread_mutex_t));
	if (philo->meal_mutex == NULL)
		return (-1);
	if (pthread_mutex_init(philo->meal_mutex, NULL) != 0)
		return (-1);
	return (0);
}
