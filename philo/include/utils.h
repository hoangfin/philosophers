/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 00:12:12 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/09 14:42:09 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "types.h"

long		ft_atol(const char *str, int *overflow);
long		now(void);
t_bool		validate(int argc, char **argv);
t_sim_state	get_sim_state(t_app *app);
void		set_sim_state(t_sim_state state, t_app *app);

int			msleep(long duration);
int			print_state(long time, int id, t_philo_state state, t_app *app);
int			set_philo_state(t_philo_state state, t_philo *philo);
int			acquire_locks(\
				pthread_mutex_t *mutexes[], \
				int num_of_mutexes, \
				void *data, \
				int (*fn)(void *data) \
			);
int			release_locks(pthread_mutex_t *mutexes[], int num_of_mutexes);

#endif
