/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:02:12 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/03 13:08:49 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "utils_bonus.h"

void	print(int id, const char *msg, t_sim *sim)
{
	lock(sim->state_mutex, "print: lock: state_mutex");
	if (sim->state != SIM_RUNNING)
		return (unlock(sim->state_mutex, "print: unlock: state_mutex"));
	lock_sem(sim->printer_sem, "print: lock_sem: printer_sem");
	if (sim->state != SIM_RUNNING)
	{
		unlock_sem(sim->printer_sem, "print: unlock_sem: printer_sem");
		unlock(sim->state_mutex, "print: unlock: state_mutex");
		return ;
	}
	if (printf("%ld %d %s\n", now() - sim->start, id, msg) < 0)
	{
		write(STDERR_FILENO, "print: printf\n", 14);
		unlock_sem(sim->printer_sem, "print: unlock_sem: printer_sem");
		unlock(sim->state_mutex, "print: unlock: state_mutex");
		exit(1);
	}
	unlock_sem(sim->printer_sem, "print: unlock_sem: printer_sem");
	unlock(sim->state_mutex, "print: unlock: state_mutex");
}
