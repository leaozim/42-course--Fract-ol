/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:20:10 by lade-lim          #+#    #+#             */
/*   Updated: 2022/07/24 21:36:31 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_hex(int nb, t_flags *flags, char spcif, t_str s)
{
	if (spcif == 'x')
	{
		s.temp = ft_strtolower(ft_uitoahex(nb));
		s.str = ft_strdup(s.temp);
		free(s.temp);
		put_flags(&s, flags, spcif);
		free(s.str);
		return (s.len);
	}
	else if (spcif == 'X')
	{
		s.temp = ft_strtolupper(ft_uitoahex(nb));
		s.str = ft_strdup(s.temp);
		free(s.temp);
		put_flags(&s, flags, spcif);
		free(s.str);
		return (s.len);
	}
	return (0);
}
