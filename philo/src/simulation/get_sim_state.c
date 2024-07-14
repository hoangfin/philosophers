/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sim_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:09:22 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/12 19:57:42 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

t_sim_state	get_sim_state(t_sim *sim)
{
	t_sim_state	state;

	if (pthread_mutex_lock(sim->state_mutex) != 0)
		return (SIM_ERROR);
	state = sim->state;
	if (pthread_mutex_unlock(sim->state_mutex) != 0)
		return (SIM_ERROR);
	return (state);
}
