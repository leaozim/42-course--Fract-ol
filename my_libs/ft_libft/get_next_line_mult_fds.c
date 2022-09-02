/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_mult_fds.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:14:05 by lade-lim          #+#    #+#             */
/*   Updated: 2022/08/15 16:29:43 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_backup(char **str)
{
	size_t	counter;

	counter = 0;
	if ((*str) == NULL)
		return (0);
	while ((*str)[counter] != '\n' && (*str)[counter])
		counter++;
	if ((*str)[counter] == '\n')
		counter++;
	return (counter);
}

static char	*save_backup(char **backup, int len)
{
	char	*aux;

	aux = ((*backup));
	(*backup) = ft_strdup(&(*backup)[len]);
	free(aux);
	return ((*backup));
}

static void	*free_ptrs(char **backup, char **buffer)
{
	if (backup)
	{
		free((*backup));
		*backup = NULL;
	}
	if (buffer)
	{
		free((*buffer));
		*buffer = NULL;
	}
	return (NULL);
}

static	char	*read_file(char *buffer, int fd, char **backup)
{
	char	*temp;
	char	*line;
	int		bytes_read;
	int		len;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (free_ptrs(backup, &buffer));
	if ((bytes_read == 0 && !(*backup)[0]))
		return (free_ptrs(backup, &buffer));
	while (bytes_read)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*backup, buffer);
		free(*backup);
		*backup = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	len = len_backup(backup);
	line = ft_substr((*backup), 0, len);
	*backup = save_backup(backup, len);
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup[1024];
	char		*buffer;
	char		*line;

	if (fd > 1024 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	*buffer = '\0';
	if (!backup[fd])
	{
		backup[fd] = ft_strdup("");
		if (!backup[fd])
			free_ptrs(backup, &buffer);
	}
	line = read_file(buffer, fd, &backup[fd]);
	return (line);
}
