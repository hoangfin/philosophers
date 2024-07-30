/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 00:12:12 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/30 22:43:44 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include <pthread.h>

long	ft_atol(const char *str, int *overflow);
long	now(void);
void	lock(pthread_mutex_t *mutex, const char *err_msg);
void	unlock(pthread_mutex_t *mutex, const char *err_msg);
int		validate(int argc, char **argv);

#endif
