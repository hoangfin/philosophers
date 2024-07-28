/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:03:44 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/28 14:26:45 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo_bonus.h"

int	init_philo(t_philo *philo, int id, t_sim *sim)
{
	philo->sim = sim;
	philo->id = id;
	philo->next_meal = 0;
	philo->meal_mutex = malloc(sizeof(pthread_mutex_t));
	if (
		philo->meal_mutex == NULL
		|| pthread_mutex_init(philo->meal_mutex, NULL) != 0
	)
		return (-1);
	return (0);
}
