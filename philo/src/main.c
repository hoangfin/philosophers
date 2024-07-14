/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:02:38 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/14 14:39:40 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "simulation.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_sim	sim;
	int		status;
	int		wstatus;

	if (validate(argc, argv + 1) == 0)
		return (EXIT_FAILURE);
	if (init(&sim, argv) == -1)
		return (EXIT_FAILURE);
	status = start(&sim);
	wstatus = wait(&sim);
	destroy(&sim);
	if (status < 0 || wstatus < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
