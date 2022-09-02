/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:29:26 by lade-lim          #+#    #+#             */
/*   Updated: 2022/06/13 20:38:49 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	size_t	*tmemory;
	size_t	max_size;

	max_size = 2147483648;
	if (nelem > max_size || elsize > max_size || nelem * elsize > max_size)
		return (0);
	tmemory = malloc (nelem * elsize);
	ft_bzero (tmemory, (nelem * elsize));
	return (tmemory);
}
