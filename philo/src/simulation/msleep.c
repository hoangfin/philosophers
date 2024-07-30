/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:16:02 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/30 21:56:45 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

/**
 * Suspends execution of the calling thread for (at least) the specified
 * duration in milliseconds.
 *
 * @returns 0 on success. On error, -1 is returned, with errno set to
 * indicate the error.
 */
void	msleep(long duration, t_sim *sim)
{
	const long	start = now();

	while (1)
	{
		if (sim != NULL)
		{
			lock(sim->state_mutex, "msleep: lock");
			if (sim->state != SIM_RUNNING)
				return (unlock(sim->state_mutex, "msleep: unlock"));
			unlock(sim->state_mutex, "msleep: unlock");
		}
		if (now() - start >= duration)
			return ;
		if (usleep(500) != 0)
		{
			write(2, "msleep: usleep\n", 15);
			exit(1);
		}
	}
}
