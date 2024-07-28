/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_locks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:12:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/28 14:21:09 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types_bonus.h"

void	release_locks(t_philo *philo)
{
	if (
		pthread_mutex_unlock(philo->meal_mutex) != 0
		|| pthread_mutex_unlock(philo->sim->state_mutex) != 0
	)
		exit(1);
}
