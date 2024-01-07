/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <adelemartin@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:57:39 by ademarti          #+#    #+#             */
/*   Updated: 2024/01/07 17:31:03 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

/*
int open(const char* path, int flags)
{
	int fd;
	fd =

	if (fd > 0)
        write(fd, &c, 1);
    else
        write(2, "test.txt not found.\n", 20);
		return (-1);

	return (1);
}

void *get_next_line(int fd, char c)
{
	fd = open("/Users/adelemartin/fd_getnextline.rtf", O_RDONLY);


}
*/

int main()
{
 int fd;
fd = open("text.txt", O_RDONLY);
}
