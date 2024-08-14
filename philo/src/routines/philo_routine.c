/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:44:14 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/14 17:54:07 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sim.h"
#include "philo.h"
#include "utils.h"

void	*philo_routine(void *arg)
{
	t_philo *const	philo = (t_philo *) arg;
	const long		delay = philo->sim->start - now();

	if (delay > 0)
		msleep(delay, NULL);
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
