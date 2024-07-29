/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   now.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 12:36:43 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/29 23:59:42 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

/**
 * Get current time since the Epoch.
 *
 * @returns current time in milliseconds, -1 in case of failure.
 */
long	now(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) < 0)
	{
		write(2, "now: gettimeofday\n", 18);
		exit(1);
	}
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}
