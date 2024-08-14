/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:35:28 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/14 17:52:12 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sim.h"
#include "utils.h"

void	ft_sleep(t_philo *philo)
{
	print(philo->id, "is sleeping", philo->sim);
	msleep(philo->sim->time_to_sleep, philo->sim);
}
