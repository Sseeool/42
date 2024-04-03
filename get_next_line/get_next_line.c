#include "get_next_line.h"
#include "get_next_line_utils.c"
#include <stdio.h>

int	find_newline(char *backup)
{
	int	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return i;
		i++;
	}
	return (-1);
}

char	*get_backup(char *backup, int fd, int *i)
{
	char	buf[BUFFER_SIZE + 1];
	char	*f_temp;
	ssize_t	read_bytes;

	if (!backup)
		backup = ft_strdup("");
	while (1)
	{
		buf[0] = '\0';
		read_bytes = read(fd, buf, BUFFER_SIZE);
		buf[read_bytes] = '\0';
		if ((read_bytes == 0 && backup[0] == '\0') || read_bytes == -1)
			return (NULL);
		if (buf[0] != '\0')
			backup = ft_strjoin(backup, buf);
		*i = find_newline(backup);
		if (*i != -1 || *i == -1 && read_bytes == 0)
			return (backup);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char	*result;
	char	*temp;
	int		i;

	temp = get_backup(backup, fd, &i);
	if (temp == NULL)
		return (NULL);
	if (i == -1)
	{
		backup = ft_strdup("");
		return (temp);
	}
	result = ft_substr(temp, 0, i + 1);
	backup = ft_substr(temp, i + 1, ft_strlen(temp));
	free(temp);
	return (result);
}

int main()
{
	int	fd;
	int	i;
	char *line;

	fd = open("./test.txt", 0);

	/*for (int i = 0; i < 10; i++)
		printf("%s", get_next_line(fd));*/
	line = get_next_line(fd);
	while (line > 0)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	return 0;
}
