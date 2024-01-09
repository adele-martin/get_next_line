/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:57:39 by ademarti          #+#    #+#             */
/*   Updated: 2024/01/09 14:41:45 by ademarti         ###   ########.fr       */
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
	printf("%s", stash);

	return (buffer);
}

//Where do I free my buffer??

char *get_next_line(int fd)
{
	//make_line();
	//update_stash();
	return (put_in_stash(fd));
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
