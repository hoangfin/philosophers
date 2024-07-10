/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:35:53 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/09 19:23:06 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "action.h"
#include "utils.h"

// static int	acquire_rl_forks(t_philo *philo)
// {
// 	if (pthread_mutex_lock(philo->right_fork) != 0)
// 		return (write(2, "pthread_mutex_lock: right_fork\n", 31), -1);
// 	if (set_philo_state(TAKE_A_FORK, "has taken a fork", philo) == -1)
// 		return (pthread_mutex_unlock(philo->right_fork), -1);
// 	if (pthread_mutex_lock(philo->left_fork) != 0)
// 	{
// 		write(2, "pthread_mutex_lock: left_fork\n", 30);
// 		return (pthread_mutex_unlock(philo->right_fork), -1);
// 	}
// 	if (set_philo_state(TAKE_A_FORK, "has taken a fork", philo) == -1)
// 	{
// 		pthread_mutex_lock(philo->left_fork);
// 		pthread_mutex_lock(philo->right_fork);
// 		return (-1);
// 	}
// 	return (0);
// }

static int	set_state(void *data)
{
	if (set_philo_state(TAKE_A_FORK, data) == -1)
		return (-1);
	return (0);
}

int	eat(t_philo *philo)
{
	pthread_mutex_t	*mutexes[2];

	mutexes[0] = philo->left_fork;
	mutexes[1] = philo->right_fork;
	if (acquire_locks(mutexes, 2, philo, set_state) == -1)
		return (-1);
	if (
		set_philo_state(EATING, philo) == -1
		|| msleep(philo->app->time_to_eat) == -1
	)
		return (release_locks(mutexes, 2), -1);
	if (release_locks(mutexes, 2) == -1)
		return (-1);
	return (0);
}
