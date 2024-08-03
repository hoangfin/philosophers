/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msleep_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:16:02 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/03 12:50:51 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils_bonus.h"

/**
 * Suspends execution of the calling thread for (at least) the specified
 * duration in milliseconds.
 */
void	msleep(long duration, long timeout)
{
	const long	start = now();
	long		elapsed_time;

	elapsed_time = now() - start;
	while (elapsed_time < duration && elapsed_time < timeout)
	{
		if (usleep(500) != 0)
		{
			write(STDERR_FILENO, "msleep: usleep\n", 15);
			exit(1);
		}
		elapsed_time = now() - start;
	}
}
