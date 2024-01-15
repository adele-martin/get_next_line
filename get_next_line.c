/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:57:39 by ademarti          #+#    #+#             */
/*   Updated: 2024/01/15 17:14:34 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static char *put_in_stash(int fd, char *buffer, char *stash)
{
	char	*temp;
	ssize_t	bytesread;

	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(stash);
			return NULL;
		}
		else if (bytesread == 0)
			break;
		buffer[bytesread] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(stash, '\n'))
			break;
	}
	return (stash);
}

static char *make_line(char *stash)
{
	size_t	i;
	char	*sub;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		i++;
	}
	if (stash[i] == '\0' || stash[1] == '\0')
		return (NULL);
	else
	{
	sub = (char *)malloc(sizeof(char) * (i + 2));
	if (!sub)
		return (NULL);
	}
	ft_strlcpy(sub, stash, i + 1);
		sub[i] = '\n';
		sub[i + 1] = '\0';
	// printf("%s", sub);
    if (*sub == 0)
    {
        free(sub);
        sub = NULL;
    }
	return (sub);
}

char *get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;
	char *result;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		free(buffer);
		stash = NULL;
		buffer = NULL;
		return (NULL);
    }

	line = put_in_stash(fd, buffer, stash);
	free(buffer);
	buffer = NULL;
	if (!line)
        return (NULL);
	result = make_line(line);
	return (result);
}

int main()
{
	int fd;
	char *result;

	fd = open("test.txt", O_RDONLY);
	result = get_next_line(fd);
	printf("%s", result);
	free(result);
	result = get_next_line(fd);
	printf("%s", result);
	free(result);

}

