/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:44:14 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/13 19:32:51 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosopher.h"
#include "simulation.h"
#include "utils.h"

void	*philosopher_routine(void *arg)
{
	t_philo *const	philo = (t_philo *) arg;

	if (philo->id % 2 == 0 && msleep(1) == -1)
		return (NULL);
	while (get_sim_state(philo->sim) == SIM_RUNNING)
	{
		if (think(philo) == -1 || eat(philo) == -1 || ft_sleep(philo) == -1)
			break ;
	}
	return (NULL);
}
