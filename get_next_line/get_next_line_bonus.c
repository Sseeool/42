/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:30:53 by eonoh             #+#    #+#             */
/*   Updated: 2024/04/05 11:09:40 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *backup)
{
	int	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_temp(char *backup, int fd, int *i)
{
	char	buf[BUFFER_SIZE + 1];
	int		read_bytes;

	if (backup == NULL)
		backup = ft_strdup("");
	while (1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes >= 0)
			buf[read_bytes] = '\0';
		if ((read_bytes == 0 && backup[0] == '\0') || read_bytes == -1)
		{
			free(backup);
			return (NULL);
		}
		if (buf[0] != '\0')
			backup = ft_strjoin(backup, buf);
		*i = find_newline(backup);
		if (*i != -1 || (*i == -1 && read_bytes == 0))
			return (backup);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*backup[1024];
	char		*result;
	char		*temp;
	int			i;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	temp = get_temp(backup[fd], fd, &i);
	if (temp == NULL)
	{
		backup[fd] = NULL;
		return (NULL);
	}
	if (i == -1)
	{
		backup[fd] = NULL;
		return (temp);
	}
	result = ft_substr(temp, 0, i + 1);
	backup[fd] = ft_substr(temp, i + 1, ft_strlen(temp));
	free(temp);
	return (result);
}
