/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:18:46 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/11 22:31:34 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnum(char *nbr)
{
	int	len;

	len = ft_strlen(nbr);
	if (nbr[len - 1] == '.')
		return (0);
	if (*nbr == '+' || *nbr == '-')
		nbr++;
	if (*nbr == '.')
		return (0);
	while (ft_isdigit(*nbr))
		nbr++;
	if (!(*nbr))
		return (1);
	nbr++;
	while (ft_isdigit(*nbr))
		nbr++;
	if (*nbr)
		return (0);
	return (1);
}
