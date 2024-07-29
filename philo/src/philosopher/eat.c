/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:35:53 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/29 23:47:54 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "utils.h"

void	eat(t_philo *philo)
{
	int	status;

	lock(philo->left_fork, "eat: lock: left_fork mutex");
	if (print_philo_state("has taken a fork", philo) != 0)
		return (unlock(philo->left_fork, "eat: unlock: left_fork mutex"));
	lock(philo->right_fork, "eat: lock: right_fork mutex");
	if (print_philo_state("has taken a fork", philo) != 0)
	{
		unlock(philo->right_fork, "eat: unlock: right_fork mutex");
		unlock(philo->left_fork, "eat: unlock: left_fork mutex");
		return ;
	}
	lock(philo->meal_mutex, "eat: lock: meal_mutex");
	philo->last_meal = now();
	philo->meal_count++;
	status = print_philo_state("is eating", philo);
	unlock(philo->meal_mutex, "eat: unlock: meal_mutex");
	if (status == 0)
		msleep(philo->sim->time_to_eat);
	unlock(philo->right_fork, "eat: unlock: right_fork mutex");
	unlock(philo->left_fork, "eat: unlock: left_fork mutex");
}
