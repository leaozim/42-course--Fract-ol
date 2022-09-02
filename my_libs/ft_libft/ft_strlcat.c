/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:14:29 by lade-lim          #+#    #+#             */
/*   Updated: 2022/06/14 01:17:39 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *str, size_t size)
{
	size_t	str_len;
	size_t	dest_len;
	size_t	i;

	str_len = ft_strlen(str);
	dest_len = 0;
	while (dest[dest_len] != '\0' && dest_len < size)
		dest_len++;
	i = 0;
	if (dest_len < size)
	{
		while (str[i] != '\0' && (i + dest_len) < (size - 1))
		{
			dest[i + dest_len] = str[i];
			i++;
		}
		dest[i + dest_len] = '\0';
	}
	return (dest_len + str_len);
}
