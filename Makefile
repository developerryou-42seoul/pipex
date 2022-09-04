# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sryou <sryou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 10:33:16 by sryou             #+#    #+#              #
#    Updated: 2022/09/04 17:28:58 by sryou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex 
LIBFT = Libft
LIBFT_LIB = ft
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

SRCS = main.c \
		parse.c \
		file.c \
		control.c
		
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	make bonus -C $(LIBFT)/
	$(CC) $(CFLAGS) $^ -L./$(LIBFT) -l$(LIBFT_LIB) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus

all : $(NAME)
clean :
	make fclean -C $(LIBFT)/
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)
re : 
	make fclean
	make all
