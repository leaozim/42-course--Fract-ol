/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:46:51 by lade-lim          #+#    #+#             */
/*   Updated: 2022/06/13 20:42:19 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*aux;

	i = 0;
	aux = malloc((ft_strlen(s) + 1) * sizeof(char));
	while (s[i] != '\0')
	{
		aux[i] = (*f)(i, s[i]);
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
