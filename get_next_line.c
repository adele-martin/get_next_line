/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:57:39 by ademarti          #+#    #+#             */
/*   Updated: 2024/01/09 15:20:36 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h" //to delete later

char *put_in_stash(int fd)
{
	static char	*stash;
	char	*buffer;

	buffer = (char*)malloc(BUFFER_SIZE);
	if (!buffer)
		return NULL;
	read(fd, buffer, BUFFER_SIZE);
	ssize_t bytesRead;
    // while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0)
	// {
    //     read(fd, buffer, BUFFER_SIZE);
    // }
	stash = buffer;
	//printf("%s", stash);

	return (stash);
}
//Where do I free my buffer??

int make_line(char *stash)
{
	size_t i;
	i = 0;
	char *sub;
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			sub = ft_substr(stash ,stash[0], stash[i]);
			break;
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
	return (0);
}

int main()
{
	int fd;
	fd = open("text.txt", O_RDONLY);
	get_next_line(fd);
	//get_next_line(fd);
	close(fd);
// FT_STRCHR
// FT_STRDUP
// FT_STRLEN
// FT_SUBSTR
// FT_STRJOIN

}
