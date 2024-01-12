/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:57:39 by ademarti          #+#    #+#             */
/*   Updated: 2024/01/12 15:00:52 by ademarti         ###   ########.fr       */
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
		stash = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(stash, '\n'))
			break;
	}
	return (stash);
}

char *make_line(char *stash)
{
	size_t i;
	i = 0;
	char *sub;
	while (stash[i] != '\0' || stash[i] == '\n')
		i++;
	if (stash[i] == '\0' || stash[1] == '\0')
		return (NULL);
	sub = ft_strdup(stash);
	printf("%s", sub);
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
	free(buffer);
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
