/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:03:54 by lade-lim          #+#    #+#             */
/*   Updated: 2022/06/13 20:42:34 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == (unsigned char) c)
			return (((char *)str) + i);
		i--;
	}
	if (str[0] == (unsigned char) c)
		return ((char *)str);
	else if (str[i] != (unsigned char) c)
		return (0);
	else if (str[i] == '\0')
		return (((char *)str) + i);
	return (0);
}
