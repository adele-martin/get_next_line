/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:57:39 by ademarti          #+#    #+#             */
/*   Updated: 2024/01/11 12:05:47 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char *put_in_stash(int fd)
{
	static char	*stash;
	char	*buffer;

	buffer = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
	size_t bytesRead;
	while (bytesRead> 0)
	{
		bytesRead = read(fd, buffer, BUFFER_SIZE);
		buffer[bytesRead] = '\0';
	// stash = buffer;
	}
	printf("%s", buffer);
	return (buffer);
}

int make_line(char *stash)
{
	size_t i;
	i = 0;
	char *sub;

	while (stash[i] != '\0')
	{
		if (ft_strchr(stash, '\n'))
		{
			sub = ft_substr(stash , 0, stash[i]);
			break;
		}
		i++;
	}
	printf("%s", sub);
	return (0);
}

char *get_next_line(int fd)
{
	put_in_stash(fd);
	make_line(put_in_stash(fd));
	//update_stash();
	return (put_in_stash(fd));
}

int main()
{
	int fd;

	fd = open("text.txt", O_RDONLY);
	// char *line = get_next_line(fd);
	get_next_line(fd);
	// free(fd);
	// printf("%s" ,line);
	//get_next_line(fd);6
	close(fd);

}
