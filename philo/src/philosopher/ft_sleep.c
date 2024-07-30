/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:35:28 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/30 22:02:04 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include "philosopher.h"
#include "utils.h"

void	ft_sleep(t_philo *philo)
{
	if (print_philo_state("is sleeping", philo) != 0)
		return ;
	msleep(philo->sim->time_to_sleep, philo->sim);
}
