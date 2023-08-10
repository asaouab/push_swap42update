# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:50:50 by asaouab           #+#    #+#              #
#    Updated: 2023/08/10 17:13:57 by asaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = push_swap
# CC = cc
# HEADER = push_swap.h
# CFLAGS = -Wall -Wextra -Werror
# SRC = check_args.c ft_atoi.c ft_functions.c ft_lalgo.c ft_sort.c ft_split.c ft_strjoin.c ft_substr.c 
# OBJECTS = $(SRC:.c=.o)

# all : $(NAME)

# $(NAME): $(OBJECTS) push_swap.h
# 	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	
# %.o : %.c push_swap.h
# 	$(CC) $(CFLAGS)  -c $<

# clean :
# 	rm -rf $(OBJECTS)

# fclean : clean
# 	rm -rf $(NAME)

# re : fclean all
# .PHONY: clean fclean

NAME = push_swap
CC = cc
HEADER = push_swap.h
CFLAGS = -Wall -Wextra -Werror
SRC = check_args.c ft_atoi.c ft_functions.c ft_lalgo.c ft_sort.c ft_split.c ft_strjoin.c ft_substr.c ft_parcing.c ft_sortcomp.c ft_swapcomp.c
OBJECTS = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

	
%.o : %.c push_swap.h
	$(CC) $(CFLAGS)  -c $<

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
.PHONY: clean fclean
