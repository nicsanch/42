# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 16:33:41 by nicsanch          #+#    #+#              #
#    Updated: 2023/09/01 20:15:19 by nicsanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = $(BIN_DIR)/libft.a

FILES = 		ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_strlen.c			\
				ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memmove.c 		\
				ft_strlcpy.c		\
				ft_strlcat.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strncmp.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strnstr.c		\
				ft_atoi.c			\
				ft_calloc.c			\
				ft_strdup.c			\
				ft_substr.c			\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_split.c			\
				ft_itoa.c			\
				ft_strmapi.c		\
				ft_striteri.c		\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_lstnew.c			\
				ft_lstadd_front.c 	\
				ft_lstsize.c 		\
				ft_lstlast.c 		\
				ft_lstadd_back.c 	\
				ft_lstdelone.c 		\
				ft_lstclear.c 		\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_number_base.c	\
				ft_printf.c			\
				ft_ptr_address.c	\
				ft_array_str_len.c	\
		
OBJS = $(addprefix $(OBJ_DIR)/,$(FILES:%.c=%.o))

INC_DIR = ./inc
OBJ_DIR = ./obj
SRC_DIR = ./src
BIN_DIR = ./bin

CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR)
	ar rcs $(TARGET) $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

all: $(TARGET)

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		rm -r $(OBJ_DIR); \
	fi

fclean: clean
	@if [ -d $(BIN_DIR) ]; then \
		rm -r $(BIN_DIR); \
	fi

re: fclean all