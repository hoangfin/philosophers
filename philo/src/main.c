/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:02:38 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/02 00:31:36 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sim.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_sim	sim;

	if (
		validate(argc, argv + 1) == 0
		|| init(&sim, argv) != 0
		|| start(&sim) != 0
		|| destroy(&sim) != 0
	)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
