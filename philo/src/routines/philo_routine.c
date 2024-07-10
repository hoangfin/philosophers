/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:44:14 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/10 18:42:59 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "action.h"
#include "utils.h"

void	*philo_routine(void *arg)
{
	t_philo *const	philo = (t_philo *) arg;

	if (philo->id % 2 == 0 && msleep(1) == -1)
		return (NULL);
	while (get_sim_state(philo->app) == SIM_RUNNING)
	{
		if (
			think(philo) == -1
			|| eat(philo) == -1
			|| ft_sleep(philo) == -1
		)
			set_sim_state(SIM_ERROR, philo->app);
	}
	return (NULL);
}
