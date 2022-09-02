/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:16:41 by lade-lim          #+#    #+#             */
/*   Updated: 2022/07/21 23:34:37 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_len_number_u(unsigned int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_uitoa(unsigned int number)
{
	size_t		len;
	char		*str;

	len = ft_len_number_u(number);
	str = malloc ((len + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	if (number == 0)
		str[0] = '0';
	str[len] = '\0';
	while (number)
	{
		str[len - 1] = DECIMAL_BASE[number % 10];
		len--;
		number /= 10;
	}
	return (str);
}
