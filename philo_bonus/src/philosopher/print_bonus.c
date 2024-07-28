/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:58:42 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/28 14:26:45 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "philo_bonus.h"
#include "utils_bonus.h"

int	print(const char *msg, t_philo *philo)
{
	long	elapsed_time;

	if (acquire_locks(philo) != 0)
		return (-1);
	if (sem_wait(philo->sim->printer) != 0)
		exit(1);
	if (philo->sim->state != SIM_RUNNING)
		return (release_locks(philo), -1);
	elapsed_time = now() - philo->sim->start;
	if (printf("%ld %d %s\n", elapsed_time, philo->id, msg) < 0)
		exit(1);
	if (sem_post(philo->sim->printer) != 0)
		exit(1);
	release_locks(philo);
	return (0);
}
