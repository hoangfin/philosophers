/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 00:12:12 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/30 21:57:26 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "types.h"

long	ft_atol(const char *str, int *overflow);
long	now(void);
t_bool	validate(int argc, char **argv);
void	lock(pthread_mutex_t *mutex, const char *err_msg);
void	unlock(pthread_mutex_t *mutex, const char *err_msg);

#endif
