/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoahex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:21:25 by lade-lim          #+#    #+#             */
/*   Updated: 2022/07/21 23:38:11 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	size_t	ft_len_number_hex(unsigned int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

char	*ft_uitoahex(unsigned int number)
{
	size_t		len;
	char		*str;

	len = ft_len_number_hex(number);
	str = malloc ((len + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	if (number == 0)
		str[0] = '0';
	str[len] = '\0';
	while (number)
	{
		str[len - 1] = HEX_BASE[number % 16];
		len--;
		number /= 16;
	}
	return (str);
}
