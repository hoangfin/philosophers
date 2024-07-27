/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sim_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:56:53 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/23 17:58:14 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "def.h"

void	set_sim_state(t_sim_state sim_state, t_sim *sim)
{
	if (pthread_mutex_lock(sim->state_mutex) != 0)
	{
		write(2, "set_sim_state: pthread_mutex_lock\n", 34);
		sim->state = SIM_ERROR;
		return ;
	}
	sim->state = sim_state;
	if (pthread_mutex_unlock(sim->state_mutex) != 0)
	{
		write(2, "set_sim_state: pthread_mutex_unlock\n", 36);
		sim->state = SIM_ERROR;
	}
}
