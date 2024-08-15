/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:02:12 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/14 23:44:34 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "utils_bonus.h"

void	print(const char *msg, t_philo *philo)
{
	lock_sem(philo->state_sem, "print: lock_sem: state");
	if (philo->is_dead || philo->has_enough_meal)
		return (unlock_sem(philo->state_sem, "print: unlock_sem: state"));
	lock_sem(philo->sim->printer_sem, "print: lock_sem: printer_sem");
	if (philo->is_dead || philo->has_enough_meal)
	{
		unlock_sem(philo->sim->printer_sem, "print: unlock_sem: printer_sem");
		unlock_sem(philo->state_sem, "print: unlock_sem: state");
		return ;
	}
	if (printf("%ld %d %s\n", now() - philo->sim->start, philo->id, msg) < 0)
	{
		write(STDERR_FILENO, "print: printf\n", 14);
		unlock_sem(philo->sim->printer_sem, "print: unlock_sem: printer_sem");
		unlock_sem(philo->state_sem, "print: unlock_sem: state");
		exit(1);
	}
	unlock_sem(philo->sim->printer_sem, "print: unlock_sem: printer_sem");
	unlock_sem(philo->state_sem, "print: unlock_sem: state");
}
