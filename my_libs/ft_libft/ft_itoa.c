/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:09:46 by lade-lim          #+#    #+#             */
/*   Updated: 2022/06/13 20:39:28 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_number(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	number;

	len = ft_len_number(n);
	number = n;
	str = malloc ((len + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	if (number == 0)
		str[0] = '0';
	if (number < 0)
	{
		str[0] = '-';
		number = number * -1;
	}
	str[len] = '\0';
	while (number)
	{
		str[len - 1] = number % 10 + '0';
		len--;
		number = number / 10;
	}
	return (str);
}
