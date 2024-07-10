/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:27:52 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/09 19:20:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "utils.h"

static int	print(long time, int id, t_philo_state state)
{
	if (state == THINKING && printf("%ld %d is thinking\n", time, id) < 0)
		return (-1);
	if (state == EATING && printf("%ld %d is eating\n", time, id) < 0)
		return (-1);
	if (state == SLEEPING && printf("%ld %d is sleeping\n", time, id) < 0)
		return (-1);
	if (state == DIED && printf("%ld %d died\n", time, id) < 0)
		return (-1);
	if (
		state == TAKE_A_FORK
		&& printf("%ld %d has taken a fork\n", time, id) < 0
	)
		return (-1);
	return (0);
}

int	print_state(long time, int id, t_philo_state state, t_app *app)
{
	pthread_mutex_t	*mutexes[2];

	mutexes[0] = app->printer;
	mutexes[1] = app->sim_state_mutex;
	if (acquire_locks(mutexes, 2, NULL, NULL) == -1)
		return (-1);
	if (app->sim_state != SIM_RUNNING)
		return (release_locks(mutexes, 2), 0);
	if (print(time, id, state) == -1)
		return (release_locks(mutexes, 2), 0);
	if (state == DIED)
		app->sim_state = SIM_END;
	if (release_locks(mutexes, 2) == -1)
		return (-1);
	return (0);
}
