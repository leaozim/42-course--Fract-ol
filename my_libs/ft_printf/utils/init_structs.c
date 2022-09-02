/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:58:54 by lade-lim          #+#    #+#             */
/*   Updated: 2022/07/25 16:21:56 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_str	init_tstr(void)
{
	t_str	new_str;

	new_str.len = 0;
	new_str.str = "";
	new_str.temp = "";
	return (new_str);
}

t_flags	init_flags(void)
{
	t_flags	new_tflags;

	new_tflags.plus = FALSE;
	new_tflags.sharp = FALSE;
	new_tflags.space = FALSE;
	return (new_tflags);
}
