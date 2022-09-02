/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:50:31 by lade-lim          #+#    #+#             */
/*   Updated: 2022/06/13 20:42:29 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *largestr, const char *smallstr, size_t len)
{
	size_t	i;
	size_t	j;

	if (*smallstr == '\0')
		return ((char *) largestr);
	i = 0;
	while (largestr[i] && i < len)
	{
		j = 0;
		while (smallstr[j] == largestr[i + j] && (i + j) < len)
		{
			j++;
			if (smallstr[j] == '\0')
				return ((char *) &(largestr[i]));
			else if (smallstr[j] != largestr[i + j] || largestr[i + j] == '\0')
				break ;
		}
		i++;
	}
	return (0);
}
