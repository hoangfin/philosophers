/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:46:06 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/07 22:10:46 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <errno.h>
#include "types.h"

int	wait(t_app *app)
{
	int			i;
	int			rc;
	pthread_t	thread;

	i = 0;
	while (i < app->number_of_threads)
	{
		thread = *(app->philos[i].thread);
		rc = pthread_join(thread, NULL);
		if (rc != 0 && rc != ESRCH && rc != EINVAL)
			return (-1);
		i++;
	}
	return (0);
}
