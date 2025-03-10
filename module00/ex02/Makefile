# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 17:20:41 by tsantana          #+#    #+#              #
#    Updated: 2025/03/10 17:35:42 by tsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= account
CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++98

SRCS	:= Account.cpp tests.cpp
OBJS	:= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re