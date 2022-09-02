/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_true_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:41:59 by lade-lim          #+#    #+#             */
/*   Updated: 2022/07/25 21:12:07 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	is_true_flags(const char **format, t_flags *flags)
{
	int	i;

	i = 0;
	if ((*format)[i] == '+')
	{
		while ((*format)[i] == '+')
			i++;
		flags->plus = TRUE;
	}
	if ((*format)[i] == ' ')
	{
		while ((*format)[i] == ' ')
			i++;
		flags->space = TRUE;
	}
	if ((*format)[i] == '#')
	{
		while ((*format)[i] == '#')
			i++;
		flags->sharp = TRUE;
	}
}
