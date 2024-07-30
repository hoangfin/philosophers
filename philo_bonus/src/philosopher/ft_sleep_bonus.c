/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:35:28 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/30 22:40:39 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sim_bonus.h"
#include "philo_bonus.h"

void	ft_sleep(t_philo *philo)
{
	if (print("is sleeping", philo) != 0)
		return ;
	msleep(philo->sim->time_to_sleep, philo->sim);
}
