/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:48:42 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/26 19:27:23 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIM_H
# define SIM_H

# define SIM_START_TIME 100

# include "def.h"

t_sim_state	get_sim_state(t_sim *sim);
int			init(t_sim *simulation, char **argv);
int			start(t_sim *simulation);

void		destroy(t_sim *simulation);
void		set_sim_state(t_sim_state sim_state, t_sim *sim);

#endif
