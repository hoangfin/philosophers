/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:24:59 by hoatran           #+#    #+#             */
/*   Updated: 2024/06/24 22:53:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

static int	is_numeric(char **argv)
{
	char	*temp;

	while (*argv != NULL)
	{
		temp = *argv;
		while (*temp != '\0')
		{
			if (!(*temp >= '0' && *temp <= '9'))
			{
				write(
					STDERR_FILENO,
					"Error: Invalid argument. Not a number\n",
					38
				);
				return (0);
			}
			temp++;
		}
		argv++;
	}
	return (1);
}

int	validate(int argc, char **argv)
{
	if (argc < 5)
	{
		write(
			STDERR_FILENO,
			"Error: Invalid Argument. Requires 4 arguments (or 5)\n",
			53
		);
		return (0);
	}
	if (!is_numeric(argv))
		return (0);
	return (1);
}
