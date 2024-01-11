/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:57:39 by ademarti          #+#    #+#             */
/*   Updated: 2024/01/11 17:07:40 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char *put_in_stash(int fd, char *buffer)
{
	static char	*stash;
	char *temp;

	int bytesRead;
	bytesRead = 1;
	while (bytesRead > 0)
	{
		bytesRead = read(fd, buffer, BUFFER_SIZE);
		if (bytesRead == -1 )
		{
			free(stash);
			return NULL;
		}
		if (bytesRead == 0)
			break;
		// buffer[bytesRead] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(stash, '\0'))
			break;
	}
	free(buffer);
	buffer = NULL;
	printf("%s", stash);
	return (stash);
}

int make_line(char *stash)
{
	size_t i;
	i = 0;
	char *sub;

	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
		{
			stash = ft_substr(stash , 0, i);
		}
		else
			i++;
	}
	printf("%s", stash);
	return (0);
}

char *get_next_line(int fd)
{
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		return NULL;
    }
	make_line(put_in_stash(fd, buffer));
	char *hey = hey;
	//update_stash();char *put_in_stash(int fd, char *buffer)
	return (hey);
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
