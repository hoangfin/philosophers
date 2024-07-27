/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:20:35 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/04 17:21:23 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static long	convert_pos(const char *num_str, int *overflow)
{
	long	number;

	number = 0;
	while (ft_isdigit(*num_str))
	{
		if (number > LONG_MAX / 10)
		{
			if (overflow != NULL)
				*overflow = 1;
			return (-1);
		}
		number = number * 10;
		if (number > LONG_MAX - (*num_str - '0'))
		{
			if (overflow != NULL)
				*overflow = 1;
			return (-1);
		}
		number += (*num_str - '0');
		num_str++;
	}
	return (number);
}

static long	convert_neg(const char *num_str, int *overflow)
{
	long	number;

	number = 0;
	while (ft_isdigit(*num_str))
	{
		if (number < LONG_MIN / 10)
		{
			if (overflow != NULL)
				*overflow = 1;
			return (0);
		}
		number = number * 10;
		if (number < LONG_MIN + (*num_str - '0'))
		{
			if (overflow != NULL)
				*overflow = 1;
			return (0);
		}
		number -= (*num_str - '0');
		num_str++;
	}
	return (number);
}

/**
 * The ft_atol() function converts the initial portion of the string
 * pointed to by str to long representation.
 *
 * This function is not thread-safe and also not async-cancel safe.
 *
 * @param	{char*}	str	The string for conversion.
 *
 * @returns	{long}		The converted value or 0 on error.
*/
long	ft_atol(const char *str, int *overflow)
{
	char	sign;
	long	number;

	sign = '+';
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = *str;
		str++;
	}
	if (sign == '+')
		number = convert_pos(str, overflow);
	else
		number = convert_neg(str, overflow);
	return (number);
}
