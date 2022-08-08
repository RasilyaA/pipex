# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tandrea <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 13:39:48 by tandrea           #+#    #+#              #
#    Updated: 2022/01/29 13:39:54 by tandrea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS	=	pipex.c ft_find_cmd.c ft_split.c ft_strjoin.c ft_strlen.c ft_strnstr.c\
			ft_strcmp.c here_doc.c get_next_line.c ft_strnjoin.c here_doc_parent.c\
			mult.c fd.c

HEADER	=	pipex.h

OBJ		=	$(patsubst %.c, %.o, $(SRCS))

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o		:	%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

clean	:
			@rm -f $(OBJ)

fclean	:	clean
			@$(RM) $(NAME)

re		:	fclean all
