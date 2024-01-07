/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <adelemartin@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:57:39 by ademarti          #+#    #+#             */
/*   Updated: 2024/01/07 17:49:19 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int *get_next_line(int fd)
{
	if (fd > 0)
		write(fd, &c, 1);
	 else
		write(2, "test.txt not found.\n", 20);
		return (-1);

	return (0);
}

int main()
{
	int fd;
	fd = open("/Users/adelemartin/fd_getnextline.rtf", O_RDONLY);

}
