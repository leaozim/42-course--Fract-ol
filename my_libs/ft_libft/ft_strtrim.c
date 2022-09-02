/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:43:23 by lade-lim          #+#    #+#             */
/*   Updated: 2022/06/13 20:42:38 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	char		*aux;

	if (s1 == NULL || set == NULL)
		return (0);
	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i] != '\0')
		i++;
	aux = (char *) s1 + i;
	i = ft_strlen(aux) - 1;
	while (ft_strchr(set, aux[i]))
		i--;
	return (ft_substr(aux, 0, i + 1));
}
