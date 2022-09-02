/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:44:01 by lade-lim          #+#    #+#             */
/*   Updated: 2022/06/13 20:41:05 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *str, size_t n)
{
	size_t	i;

	i = 0;
	if (str == 0 || dest == 0)
		return (dest);
	if (ft_strlen(dest) < ft_strlen(str))
		while (n--)
			((unsigned char *) dest)[n] = ((unsigned char *) str)[n];
	else
	{
		while (i < n)
		{
			((unsigned char *) dest)[i] = ((unsigned char *) str)[i];
			i++;
		}
	}
	return (dest);
}
