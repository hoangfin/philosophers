/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sim_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:01:59 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/07 11:04:33 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	set_sim_state(t_sim_state state, t_app *app)
{
	pthread_mutex_lock(app->sim_state_mutex);
	app->sim_state = state;
	pthread_mutex_unlock(app->sim_state_mutex);
}
