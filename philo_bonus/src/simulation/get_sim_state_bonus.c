/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sim_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:56:53 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/28 14:21:09 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "types_bonus.h"

t_sim_state	get_sim_state(t_sim *sim)
{
	t_sim_state	state;

	if (pthread_mutex_lock(sim->state_mutex) != 0)
	{
		write(2, "get_sim_state: pthread_mutex_lock\n", 34);
		sim->state = SIM_ERROR;
		return (SIM_ERROR);
	}
	state = sim->state;
	if (pthread_mutex_unlock(sim->state_mutex) != 0)
	{
		write(2, "get_sim_state: pthread_mutex_unlock\n", 36);
		sim->state = SIM_ERROR;
		return (SIM_ERROR);
	}
	return (state);
}
