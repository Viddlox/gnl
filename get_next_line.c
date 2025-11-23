/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigger <nigger@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:46:16 by nigger            #+#    #+#             */
/*   Updated: 2025/11/17 21:46:16 by nigger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char **prev)
{
    size_t	i;
	char	*tmp;
    char	*res;

	i = 0;
	if (!*prev || **prev == '\0')
		return (NULL);
	while ((*prev)[i] && ((*prev)[i] != '\n'))
		i++;
    res = malloc(i + 1 + ((*prev)[i] == '\n'));
    if (!res)
        return (NULL);
    i = 0;
    while ((*prev)[i] && ((*prev)[i] != '\n'))
    {
		res[i] = (*prev)[i];
		i++;
	}
    if ((*prev)[i] == '\n')
        res[i++] = '\n';
    res[i] = '\0';
	tmp = ft_strdup_gnl(*prev + i);
	free(*prev);
	*prev = tmp;
    return (res);
}

char	*get_next_line(int fd)
{
	ssize_t		bytes;
	char		*buffer;
	static char	*prev;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strchr_gnl(prev))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		prev = ft_strjoin_gnl(prev, buffer, bytes);
	}
	free(buffer);
	return (ft_get_line(&prev));
}
