/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sim_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:09:22 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/07 21:58:44 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "types.h"

t_sim_state	get_sim_state(t_app *app)
{
	t_sim_state	state;

	if (pthread_mutex_lock(app->sim_state_mutex) != 0)
	{
		write(2, "pthread_mutex_lock: sim_state_mutex\n", 36);
		return (SIM_ERROR);
	}
	state = app->sim_state;
	if (pthread_mutex_unlock(app->sim_state_mutex) != 0)
	{
		write(2, "pthread_mutex_unlock: sim_state_mutex\n", 38);
		return (SIM_ERROR);
	}
	return (state);
}
