/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:35:28 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/29 19:33:38 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "utils.h"

void	ft_sleep(t_philo *philo)
{
	if (print_philo_state("is sleeping", philo) != 0)
		return ;
	msleep(philo->sim->time_to_sleep);
}
