/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:02:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/13 16:53:52 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_philo_state	get_philo_state(t_philo *philo)
{
	t_philo_state	state;

	if (pthread_mutex_lock(philo->state_mutex) != 0)
		return (PHILO_UNDEFINED);
	state = philo->state;
	if (pthread_mutex_unlock(philo->state_mutex) != 0)
		return (PHILO_UNDEFINED);
	return (state);
}
