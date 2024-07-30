/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:48:42 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/30 21:58:10 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "types.h"

int		init(t_sim *simulation, char **argv);
void	msleep(long duration, t_sim *sim);
int		start(t_sim *simulation);
int		wait(t_sim *simulation);
void	destroy(t_sim *simulation);

#endif
