/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:16:02 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/10 23:26:17 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

/**
 * Suspends execution of the calling thread for (at least) the specified
 * duration in milliseconds.
 *
 * @returns 0 on success. On error, -1 is returned, with errno set to
 * indicate the error.
 */
int	msleep(long duration)
{
	const long	start = now();
	long		current_time;

	current_time = now();
	if (start == -1 || current_time == -1)
		return (-1);
	while (current_time - start < duration)
	{
		if (usleep(500) == -1)
			return (-1);
		current_time = now();
		if (current_time == -1)
			return (-1);
	}
	return (0);
}
