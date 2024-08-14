/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:16:02 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/14 23:21:25 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

/**
 * Suspends execution of the calling thread for (at least) the specified
 * duration in milliseconds.
 */
void	msleep(long duration, t_sim *sim)
{
	const long	end = now() + duration;

	while (now() < end)
	{
		if (sim != NULL)
		{
			lock(sim->state_mutex, "msleep: lock: state_mutex");
			if (sim->state != SIM_RUNNING)
			{
				unlock(sim->state_mutex, "msleep: unlock: state_mutex");
				return ;
			}
			unlock(sim->state_mutex, "msleep: unlock: state_mutex");
		}
		if (usleep(500) != 0)
		{
			write(STDERR_FILENO, "msleep: usleep\n", 15);
			exit(1);
		}
	}
}
