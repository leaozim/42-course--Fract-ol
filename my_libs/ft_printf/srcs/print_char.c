/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:08:59 by lade-lim          #+#    #+#             */
/*   Updated: 2022/07/24 21:37:06 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_char(int character, t_flags *flags, char spcif, t_str s)
{
	s.temp = malloc(sizeof(char) + 1);
	s.temp[0] = character;
	s.temp[1] = '\0';
	s.str = s.temp;
	put_flags(&s, flags, spcif);
	free(s.str);
	return (s.len);
}
