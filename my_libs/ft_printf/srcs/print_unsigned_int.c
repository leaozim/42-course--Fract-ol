/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:50:51 by lade-lim          #+#    #+#             */
/*   Updated: 2022/07/22 21:07:54 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_unsigned_int(int number, t_flags *flags, char spcif, t_str s)
{
	if (number == '\0')
	{
		write(1, "0", 1);
		return (1);
	}
	s.temp = ft_uitoa(number);
	s.str = ft_strdup(s.temp);
	free(s.temp);
	put_flags(&s, flags, spcif);
	free(s.str);
	return (s.len);
}
