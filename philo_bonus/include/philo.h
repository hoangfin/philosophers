/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:11:54 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/27 21:14:31 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "def.h"

int		init_philo(t_philo *philo, int id, t_sim *sim);
void	philo_routine(t_philo *philo);
int		print(const char *msg, t_philo *philo);
int		acquire_locks(t_philo *philo);

void	release_locks(t_philo *philo);
void	think(t_philo *philo);
void	eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
#endif
