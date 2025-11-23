/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigger <nigger@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 03:00:10 by nigger            #+#    #+#             */
/*   Updated: 2025/11/22 03:00:10 by nigger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *prev, char *buffer, ssize_t bytes)
{
	size_t	i;
	ssize_t	j;
	char	*res;

	i = 0;
	if (!buffer)
		return (NULL);
	while (prev && prev[i])
		i++;
	res = malloc(i + bytes + 1);
	if (!res)
		return (free(prev), NULL);
	i = 0;
	while (prev && prev[i])
	{
		res[i] = prev[i];
		i++;
	}
	j = 0;
	while (j < bytes)
		res[i++] = buffer[j++];
	res[i] = '\0';
	free(prev);
	return (res);
}

char	*ft_strdup_gnl(char *s)
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
