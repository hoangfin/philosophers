/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:35:28 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/27 20:29:12 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "philo.h"
#include "utility.h"

void	ft_sleep(t_philo *philo)
{
	if (print("is sleeping", philo) != 0)
		return ;
	if (msleep(philo->sim->time_to_sleep) == -1)
		exit(1);
}
