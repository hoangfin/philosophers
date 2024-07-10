/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:35:28 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/09 01:04:49 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "action.h"
#include "utils.h"

int	ft_sleep(t_philo *philo)
{
	if (set_philo_state(SLEEPING, philo) == -1)
		return (-1);
	if (msleep(philo->app->time_to_sleep) == -1)
		return (-1);
	return (0);
}
