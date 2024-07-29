/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:11:54 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/29 23:39:07 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "types.h"

int		init_philosopher(t_philo *philo, int id, t_sim	*sim);
void	think(t_philo *philo);
void	eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
int		print_philo_state(const char *msg, t_philo *philo);

#endif
