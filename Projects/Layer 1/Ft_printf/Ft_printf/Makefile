# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 17:21:57 by nicsanch          #+#    #+#              #
#    Updated: 2023/07/26 18:10:43 by nicsanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf.c			\
		ft_number_base.c	\
		ft_ptr_address.c	\

OBJECTS = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

$(NAME):$(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	
%.o: %.c
	gcc $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re
	
all: $(NAME)
	
clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all