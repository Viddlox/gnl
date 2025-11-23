/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigger <nigger@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:43:31 by nigger            #+#    #+#             */
/*   Updated: 2025/11/17 21:43:31 by nigger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define MAX_FD 1024

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *prev, char *buffer, ssize_t bytes);
char	*ft_get_line(char **prev);
char	*ft_strdup_gnl(char *s);

#endif