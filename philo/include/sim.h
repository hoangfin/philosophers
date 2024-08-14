/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:48:42 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/14 16:50:46 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIM_H
# define SIM_H

# include "types.h"

int		init(t_sim *simulation, char **argv);
int		start(t_sim *simulation);
int		destroy(t_sim *simulation);
void	msleep(long duration, t_sim *sim);

#endif
