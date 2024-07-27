/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:02:38 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/19 00:42:20 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sim.h"
#include "utility.h"

int	main(int argc, char **argv)
{
	t_sim	sim;

	if (validate(argc, argv + 1) == 0)
		return (EXIT_FAILURE);
	if (init(&sim, argv) == -1)
		return (EXIT_FAILURE);
	if (start(&sim) == -1)
		return (destroy(&sim), EXIT_FAILURE);
	destroy(&sim);
	return (EXIT_SUCCESS);
}
