/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 00:12:12 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/13 18:35:28 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "types.h"

long	ft_atol(const char *str, int *overflow);
long	now(void);
t_bool	validate(int argc, char **argv);
int		msleep(long duration);
int		acquire_locks(pthread_mutex_t *mutexes[], int mutex_count);
int		release_locks(pthread_mutex_t *mutexes[], int mutex_count);

#endif
