/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:48:42 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/30 22:37:18 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIM_BONUS_H
# define SIM_BONUS_H

# define SIM_START_TIME 100

# include "types_bonus.h"

t_sim_state	get_sim_state(t_sim *sim);
int			init(t_sim *simulation, char **argv);
int			start(t_sim *simulation);

void		msleep(long duration, t_sim *sim);
void		destroy(t_sim *simulation);
void		set_sim_state(t_sim_state sim_state, t_sim *sim);

#endif
