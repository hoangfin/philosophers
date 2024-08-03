/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:02:12 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/02 17:07:18 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "utils.h"

void	print(int id, const char *msg, t_sim *sim)
{
	lock(sim->state_mutex, "print: lock: sim->state_mutex");
	if (sim->state != SIM_RUNNING)
		return (unlock(sim->state_mutex, "print: unlock: sim->state_mutex"));
	lock(sim->printer_mutex, "print: lock: sim->printer_mutex");
	if (sim->state != SIM_RUNNING)
	{
		unlock(sim->printer_mutex, "print: unlock: sim->printer_mutex");
		unlock(sim->state_mutex, "print: unlock: sim->state_mutex");
		return ;
	}
	if (printf("%ld %d %s\n", now() - sim->start, id, msg) < 0)
	{
		write(STDERR_FILENO, "print: printf\n", 14);
		exit(1);
	}
	unlock(sim->printer_mutex, "print: unlock: sim->printer_mutex");
	unlock(sim->state_mutex, "print: unlock: sim->state_mutex");
}
