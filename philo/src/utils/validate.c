/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:24:59 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/14 19:52:24 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

static t_bool	has_NaN(char **argv)
{
	char	*temp;

	while (*argv != NULL)
	{
		temp = *argv;
		if (*temp == '\0')
			return (true);
		while (*temp != '\0')
		{
			if (*temp == '-' || *temp == '+')
			{
				if (*(temp + 1) == '\0' || temp != *argv)
					return (true);
			}
			if (
				!(*temp >= '0' && *temp <= '9')
				&& *temp != '-'
				&& *temp != '+'
			)
				return (true);
			temp++;
		}
		argv++;
	}
	return (false);
}

static t_bool	has_invalid_number(char **argv)
{
	int		overflow;
	long	number;

	overflow = 0;
	while (*argv != NULL)
	{
		number = ft_atol(*argv, &overflow);
		if (overflow)
			return (write(2, "Error: Number out of range\n", 27), true);
		if (number <= 0)
			return (write(2, "Error: Number must be > 0\n", 26), true);
		argv++;
	}
	return (false);
}

t_bool	validate(int argc, char **argv)
{
	(void)argv;
	if (argc < 5 || argc > 6)
		return (write(2, "Error: Invalid number of arguments\n", 35), false);
	if (has_NaN(argv))
		return (write(2, "Error: Not a number\n", 20), false);
	if (has_invalid_number(argv))
		return (false);
	return (true);
}
