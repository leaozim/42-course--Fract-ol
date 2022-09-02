/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:10:22 by lade-lim          #+#    #+#             */
/*   Updated: 2022/07/25 15:41:19 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"			

static void	write_lowx_uppx(char spcif)
{
	if (spcif == 'x')
		write(1, "0x", 2);
	else if (spcif == 'X')
		write(1, "0X", 2);
}

void	put_flags(t_str *s, t_flags *flags, char spcif)
{
	s->len = 0;
	if (flags->plus && (spcif == 'd' || spcif == 'p'))
	{	
		if (s->str[0] != '-')
		{
			write(1, "+", 1);
			s->len += 1;
		}
		flags->space = FALSE;
	}
	if (flags->space && (spcif == 'd' || spcif == 'p' ) && s->str[0] != '-')
	{
		write(1, " ", 1);
		s->len += 1;
	}
	if (flags->sharp && (spcif == 'x' || spcif == 'X') && s->str[0] != '0')
	{
		write_lowx_uppx(spcif);
		s->len += 2;
		flags->sharp = FALSE;
	}
	if (spcif == 'c')
		s->len += ft_putchar_len(s);
	s->len += ft_putstr_len(s->str);
}
