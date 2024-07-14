/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:11:54 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/13 17:26:05 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "types.h"

int				init_philosopher(t_philo *philo, int id, t_sim	*sim);
int				think(t_philo *philo);
int				eat(t_philo *philo);
int				ft_sleep(t_philo *philo);
int				set_philo_state(t_philo_state state, t_philo *philo);
t_philo_state	get_philo_state(t_philo *philo);

#endif
