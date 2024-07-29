/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:06:10 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/29 23:56:30 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int	print_philo_state(const char *msg, t_philo *philo)
{
	long	elapsed_time;

	lock(philo->sim->state_mutex, "lock: state_mutex");
	if (philo->sim->state != SIM_RUNNING)
		return (unlock(philo->sim->state_mutex, "unlock: state_mutex"), -1);
	lock(philo->sim->printer_mutex, "lock: printer_mutex");
	if (philo->sim->state != SIM_RUNNING)
	{
		unlock(philo->sim->printer_mutex, "unlock: printer_mutex");
		unlock(philo->sim->state_mutex, "unlock: state_mutex");
		return (-1);
	}
	elapsed_time = now() - philo->sim->start;
	if (printf("%ld %d %s\n", elapsed_time, philo->id, msg) < 0)
		exit(1);
	unlock(philo->sim->printer_mutex, "print_philo_state: unlock");
	unlock(philo->sim->state_mutex, "print_philo_state: unlock");
	return (0);
}
