/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:36:24 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/06 20:24:05 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *str)
{
	double	res1;
	double	res2;
	int		len;
	char	*str_aux;

	str_aux = str;
	res1 = (double)ft_atoi(str);
	while (*str_aux && *str_aux != '.')
		str_aux++;
	if (*str_aux == '.')
		str_aux++;
	res2 = (double)ft_atoi(str_aux);
	len = ft_strlen(str_aux);
	while (len--)
		res2 /= 10;
	if (res1 >= 0)
		return (res1 + res2);
	if (res1 < 0)
		return (res1 + (res2 * (1 * -1)));
	return (0);
}
