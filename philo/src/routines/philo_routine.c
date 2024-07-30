/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:44:14 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/30 21:59:25 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "simulation.h"
#include "utils.h"

void	*philo_routine(void *arg)
{
	t_philo *const	philo = (t_philo *) arg;

	if (philo->id % 2 == 0)
		msleep(1, NULL);
	while (1)
	{
		lock(philo->sim->state_mutex, "philo_routine: lock");
		if (philo->sim->state != SIM_RUNNING)
		{
			unlock(philo->sim->state_mutex, "philo_routine: unlock");
			break ;
		}
		unlock(philo->sim->state_mutex, "philo_routine: unlock");
		think(philo);
		eat(philo);
		ft_sleep(philo);
	}
	return (NULL);
}
