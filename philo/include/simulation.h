/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:48:42 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/13 13:16:21 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "types.h"

int			init(t_sim *simulation, char **argv);
int			start(t_sim *simulation);
int			wait(t_sim *simulation);
void		destroy(t_sim *simulation);
t_sim_state	get_sim_state(t_sim *sim);
void		set_sim_state(t_sim_state state, t_sim *sim);

#endif
