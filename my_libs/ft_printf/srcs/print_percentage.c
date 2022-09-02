/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percentage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:29:50 by lade-lim          #+#    #+#             */
/*   Updated: 2022/07/22 21:12:29 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"			

int	print_percentage(int percent, t_str s)
{
	write (1, &percent, 1);
	s.len = 1;
	return (s.len);
}
