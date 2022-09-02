/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:53:06 by lade-lim          #+#    #+#             */
/*   Updated: 2022/07/22 20:10:53 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"			

int	print_int(int number, t_flags *flags, char spcif, t_str s)
{
	s.temp = ft_itoa(number);
	s.str = ft_strdup(s.temp);
	free(s.temp);
	put_flags(&s, flags, spcif);
	free(s.str);
	return (s.len);
}
