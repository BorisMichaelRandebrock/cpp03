# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 13:00:26 by brandebr          #+#    #+#              #
#    Updated: 2024/09/23 19:09:23 by brandebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap

SRC = main.cpp ClapTrap.cpp

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g

all: Makefile $(NAME)

$(OBJ_DIR)%.o: %.cpp Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

valgrind: $(NAME)
	@valgrind --leak-check=full --track-origins=yes ./$(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -rf $(OBJ_DIR)
	/bin/rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
