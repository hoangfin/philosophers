/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:27:52 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/13 14:46:10 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printer.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	print_error(const char *err_msg, t_sim *sim)
{
	pthread_mutex_lock(sim->print_mutex);
	pthread_mutex_lock(sim->state_mutex);
	if (sim->state == SIM_RUNNING)
	{
		write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
		sim->state = SIM_ERROR;
	}
	pthread_mutex_unlock(sim->state_mutex);
	pthread_mutex_unlock(sim->print_mutex);
}
