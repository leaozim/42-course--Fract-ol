/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_void_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:34:10 by lade-lim          #+#    #+#             */
/*   Updated: 2022/07/22 20:11:34 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"			

int	print_void_hex(void *point, t_flags *flags, char spcif, t_str s)
{
	size_t	number;

	if (point == NULL)
		return (ft_putstr_len("(nil)"));
	number = (size_t)point;
	s.temp = ft_uipoint_hex(number);
	s.str = ft_strjoin("0x", s.temp);
	free(s.temp);
	put_flags(&s, flags, spcif);
	free(s.str);
	return (s.len);
}
