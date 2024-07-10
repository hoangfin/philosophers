/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:11:54 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/05 17:10:00 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "types.h"

int		init(t_app *app, char **argv);
int		start(t_app *app);
int		wait(t_app *app);
void	destroy(t_app *app);
void	*philo_routine(void *arg);
void	*monitor_routine(void *arg);

#endif
