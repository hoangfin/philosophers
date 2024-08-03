/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:11:54 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/03 18:48:50 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "types_bonus.h"

void	philo_routine(t_philo *philo);
void	*monitor_routine(void *arg);
void	think(t_philo *philo);
void	eat(t_philo *philo);
void	ft_sleep(t_philo *philo);

#endif
