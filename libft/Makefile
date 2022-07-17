# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tasian <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 14:49:09 by tasian            #+#    #+#              #
#    Updated: 2020/11/13 19:37:48 by tasian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
HEADER := libft.h
FUNC :=  ft_atoi.c ft_isascii.c ft_memchr.c ft_putchar_fd.c ft_strchr.c \
		ft_strlen.c ft_strtrim.c ft_bzero.c ft_isdigit.c ft_memcmp.c \
		ft_putendl_fd.c ft_strdup.c ft_strmapi.c ft_substr.c ft_calloc.c \
		ft_isprint.c ft_memcpy.c ft_putnbr_fd.c ft_strjoin.c ft_strncmp.c \
		ft_tolower.c ft_isalnum.c ft_itoa.c ft_memmove.c ft_putstr_fd.c \
		ft_strlcat.c ft_strnstr.c ft_toupper.c ft_isalpha.c ft_memccpy.c \
		ft_memset.c ft_split.c ft_strlcpy.c ft_strrchr.c ft_lstnew.c \
		ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ := $(FUNC:%.c=%.o)

FLGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $?
	ranlib $(NAME)

%.o: %.c $(HEADER)
	gcc -c  -Wall -Wextra -Werror $< $(FLGS) -I $(HEADER) -o $@

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all
