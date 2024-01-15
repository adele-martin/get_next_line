/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:53:38 by ademarti          #+#    #+#             */
/*   Updated: 2024/01/15 18:38:55 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

static char *put_in_stash(int fd, char *buffer, char *stash);
static char *make_line(char *stash);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*remove_line_from_stash(char *stash, char *line);
// static char *put_in_stash(int fd, char *buffer, char *stash);
// char *get_next_line(int fd);
// static char *make_line(char *stash);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
// static char    *ft_strchr(char *s, int c);

#endif
