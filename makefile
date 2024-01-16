# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 15:30:21 by ademarti          #+#    #+#              #
#    Updated: 2024/01/16 12:05:53 by ademarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= get_next_line.a

SRCS = get_next_line_utils.c get_next_line.c\

OBJS := $(SRCS:%.c=%.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus
