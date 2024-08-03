/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 00:12:12 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/03 18:45:56 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "types_bonus.h"

long	ft_atol(const char *str, int *overflow);
long	now(void);

void	print(int id, const char *msg, t_sim *sim);
void	lock(pthread_mutex_t *mutex, const char *err_msg);
void	lock_sem(sem_t *semaphore, const char *err_msg);
void	msleep(long duration, long timeout);
void	unlock(pthread_mutex_t *mutex, const char *err_msg);
void	unlock_sem(sem_t *semaphore, const char *err_msg);

int		validate(int argc, char **argv);

#endif
