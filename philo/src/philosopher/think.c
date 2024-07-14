/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:40:33 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/13 16:20:36 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philosopher.h"
#include "printer.h"

int	think(t_philo *philo)
{
	if (set_philo_state(PHILO_THINKING, philo) == -1)
	{
		print_error("Error: set_philo_state", philo->sim);
		return (-1);
	}
	return (0);
}
