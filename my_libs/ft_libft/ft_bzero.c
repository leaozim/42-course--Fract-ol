/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 00:07:54 by lade-lim          #+#    #+#             */
/*   Updated: 2022/06/14 02:09:16 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t n)
{
	unsigned char	*aux;
	size_t			i;

	aux = (unsigned char *) str;
	i = 0;
	while (i < n)
	{
		aux[i] = '\0';
		aux++;
		n--;
	}
	return ((void *) str);
}
