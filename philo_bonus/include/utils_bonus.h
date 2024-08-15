/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 00:12:12 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/15 20:18:38 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "types_bonus.h"

long	ft_atol(const char *str, int *overflow);
long	now(void);

void	lock_sem(sem_t *semaphore, const char *err_msg);
void	unlock_sem(sem_t *semaphore, const char *err_msg);
void	set_name(char *buf, const char *name, int id);

int		validate(int argc, char **argv);

#endif
