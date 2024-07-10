/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:30:32 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/05 21:46:16 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include "types.h"

int	think(t_philo *philo);
int	eat(t_philo *philo);
int	ft_sleep(t_philo *philo);

#endif
