/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sim_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:01:59 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/12 19:59:48 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

void	set_sim_state(t_sim_state state, t_sim *sim)
{
	pthread_mutex_lock(sim->state_mutex);
	sim->state = state;
	pthread_mutex_unlock(sim->state_mutex);
}
