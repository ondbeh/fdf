/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:02:00 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/19 09:06:29 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi_base(const char *str, int base)
{
	int		sign;
	int		result;
	int		digit;

	sign = 1;
	result = 0;
	while (ft_is_space(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (ft_isdigit(*str)
		|| (*str >= 'a' && *str <= 'a' + base - 10)
		|| (*str >= 'A' && *str <= 'A' + base - 10))
	{
		digit = *str - '0';
		if (digit > 9)
			digit = ft_tolower(*str) - 'a' + 10;
		result = result * base + digit;
		++str;
	}
	return (result * sign);
}
