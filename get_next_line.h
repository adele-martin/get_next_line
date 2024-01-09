/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:53:38 by ademarti          #+#    #+#             */
/*   Updated: 2024/01/09 17:58:58 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char *put_in_stash(int fd);
char *get_next_line(int fd);
int make_line(char *stash);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
