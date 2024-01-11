/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:57:39 by ademarti          #+#    #+#             */
/*   Updated: 2024/01/11 17:48:48 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char *put_in_stash(int fd, char *buffer, char *stash)
{
	char *temp;

	ssize_t bytesRead;
	bytesRead = 1;
	while (bytesRead > 0)
	{
		bytesRead = read(fd, buffer, BUFFER_SIZE);
		if (bytesRead == -1 )
		{
			free(stash);
			return NULL;
		}
		else if (bytesRead == 0)
			break;
		buffer[bytesRead] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(buffer, temp);
		free(temp);
		temp = NULL;
		free(buffer);
		buffer = NULL;
		if (ft_strchr(stash, '\0'))
			break;
	}
	printf("%s", stash);
	return (stash);
}

char *make_line(char *stash)
{
	size_t i;
	i = 0;
	char *sub;

	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
		{
			sub = ft_substr(stash , stash[0], i);
		}
		else
			i++;
	}
	// printf("%s", stash);
	return (sub);
}

char *get_next_line(int fd)
{
	char	*buffer;
	char *line;
	static char	*stash;

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
	// free(buffer);
	buffer = NULL;
	if (!line)
        return (NULL);
	stash = make_line(line);
	//update_stash();char *put_in_stash(int fd, char *buffer)
	return (stash);
}

int main()
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	// char *lins = get_next_line(fd);
	get_next_line(fd);
	// free(fd);
	// printf("%s" ,line);
	//get_next_line(fd);6
	// close(fd);

}
