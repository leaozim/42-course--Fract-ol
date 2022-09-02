/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:10:51 by lade-lim          #+#    #+#             */
/*   Updated: 2022/07/22 19:36:43 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr_len(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	return (len);
}
