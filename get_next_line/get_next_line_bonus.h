/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:30:53 by eonoh             #+#    #+#             */
/*   Updated: 2024/03/29 20:18:20 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

size_t  ft_strlen(char const *str);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		find_newline(char *backup);
char	*get_backup(char **backup, int fd, int *i);
char	*get_next_line(int fd);

#endif