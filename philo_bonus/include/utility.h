/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 00:12:12 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/17 16:22:27 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

# include <semaphore.h>

long	ft_atol(const char *str, int *overflow);
long	now(void);
int		validate(int argc, char **argv);
int		msleep(long duration);

#endif
