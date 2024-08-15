/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msleep_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:16:02 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/14 23:59:58 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils_bonus.h"

/**
 * Suspends execution of the calling thread for (at least) the specified
 * duration in milliseconds.
 */
void	msleep(long duration, t_philo *philo)
{
	const long	end = now() + duration;

	while (now() < end)
	{
		if (philo != NULL)
		{
			lock_sem(philo->state_sem, "msleep: lock state_sem");
			if (philo->is_dead || philo->has_enough_meal)
			{
				unlock_sem(philo->state_sem, "msleep: unlock state_sem");
				return ;
			}
			unlock_sem(philo->state_sem, "msleep: unlock state_sem");
		}
		if (usleep(500) != 0)
		{
			write(STDERR_FILENO, "msleep: usleep\n", 15);
			exit(1);
		}
	}
}
