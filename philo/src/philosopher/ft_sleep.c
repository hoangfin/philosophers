/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:35:28 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/13 16:21:53 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "printer.h"
#include "utils.h"

int	ft_sleep(t_philo *philo)
{
	if (set_philo_state(PHILO_SLEEPING, philo) == -1)
	{
		print_error("Error: set_philo_state", philo->sim);
		return (-1);
	}
	if (msleep(philo->sim->time_to_sleep) == -1)
	{
		print_error("Error: msleep", philo->sim);
		return (-1);
	}
	return (0);
}
