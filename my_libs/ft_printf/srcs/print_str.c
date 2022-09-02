/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:47:48 by lade-lim          #+#    #+#             */
/*   Updated: 2022/07/24 21:37:23 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_str(char *str, t_flags *flags, char spcif, t_str s)
{
	if (!str && str == (char *) NULL)
		return (ft_putstr_len("(null)"));
	s.str = ft_strdup(str);
	put_flags(&s, flags, spcif);
	free(s.str);
	return (s.len);
}
