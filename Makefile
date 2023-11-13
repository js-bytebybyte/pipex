# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 17:32:01 by jolandestee       #+#    #+#              #
#    Updated: 2023/11/13 16:57:21 by jsteenpu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable file / name
NAME = pipex

# Compiling and CFLAGS
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files 
SRCS = srcs/main.c \
		srcs/pipex.c \
		srcs/children.c \
		srcs/pipex_utils.c \
		srcs/utils.c
		
# Object files 
SRCS_OBJS = $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRCS_OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) -Llibft -lft -o $@ $^

all: $(NAME)

clean:
	make clean -C ./libft 
	rm -f $(SRCS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re