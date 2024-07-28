/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:11:54 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/28 14:26:19 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "types_bonus.h"

int		init_philo(t_philo *philo, int id, t_sim *sim);
void	philo_routine(t_philo *philo);
int		print(const char *msg, t_philo *philo);
int		acquire_locks(t_philo *philo);

void	release_locks(t_philo *philo);
void	think(t_philo *philo);
void	eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
#endif
