/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msleep_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:16:02 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/01 16:56:31 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "types_bonus.h"
#include "utils_bonus.h"

/**
 * Suspends execution of the calling thread for (at least) the specified
 * duration in milliseconds.
 */
void	msleep(long duration, t_sim *sim)
{
	const long	start = now();
	long		current_time;
	long		max_duration;

	max_duration = start + duration;
	if (sim != NULL)
		max_duration = start + sim->time_to_die;
	current_time = now();
	while (current_time - start < duration && current_time < max_duration)
	{
		if (usleep(500) != 0)
		{
			write(2, "msleep: usleep\n", 15);
			exit(1);
		}
		current_time = now();
	}
}
