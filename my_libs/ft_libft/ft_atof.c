/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:36:24 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/13 00:45:03 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *str)
{
	int		sign;
	double	result;
	double	decimal;

	sign = 1;
	result = 0;
	decimal = 0.1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str++))
		result *= 10 + (*str - '0');
	while (ft_isdigit(*str))
	{
		result += (*str++ - '0') * decimal;
		decimal /= 10;
	}
	return (result * sign);
}
