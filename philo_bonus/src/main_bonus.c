/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:02:38 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/03 16:03:15 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sim_bonus.h"
#include "utils_bonus.h"

int	main(int argc, char **argv)
{
	t_sim	sim;

	if (
		validate(argc, argv + 1) == 0
		|| init(&sim, argv + 1) != 0
		|| start(&sim) != 0
		|| destroy(&sim) != 0
	)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
